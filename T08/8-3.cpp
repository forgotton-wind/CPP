#include <iostream>
#include <string>
#define SNUM 2
#define TNUM 2
#define ANUM 2

using namespace std;

class Person {
protected:
	string name;
	string gender;
	int age;
public:
	Person() {}
	Person(string n, string g, int a) :name(n), gender(g), age(a) {}
	~Person() {}
};

class Student :public Person {
private:
	string sno;
	string major;
public:
	Student() {}
	Student(string n, string g, int a, string s, string m) :Person(n, g, a), sno(s), major(m) {}
	void enroll() { cout << "一名学生招募完成!" << endl; }
	void showStudent();
	void likeOrNot();
	~Student() {}
};

class Teacher :public Person {
private:
	string tno;
	string college;
public:
	Teacher() {}
	Teacher(string n, string g, int a, string t, string c) :Person(n, g, a), tno(t), college(c) {}
	void recruit() { cout << "一名教师招募完成!" << endl; }
	void showTeacher();
	void course();
	~Teacher() {}
};

class Administrator :public Person {
private:
	string ano;
	string section;
public:
	Administrator() {}
	Administrator(string n, string g, int a, string an, string s) :Person(n, g, a), ano(an), section(s) {}
	void Employ() { cout << "一名管理人员招募完成!" << endl; }
	void showAdministrator();
	void manageStudent();
	void arrangeCourse();
	~Administrator() {}
};

class University {
private:
	string uname;
	string uaddress;
	Student S[SNUM];
	Teacher T[TNUM];
	Administrator A[ANUM];
public:
	University() {}
	void TermBegin();
	void showUniversity();
	~University() {}
};

void Student::showStudent()
{
	cout << name << " " << gender << " " << age << " " << sno << " " << major << endl;
}

void Teacher::showTeacher()
{
	cout << name << " " << gender << " " << age << " " << tno << " " << college << endl;
}

void Administrator::showAdministrator()
{
	cout << name << " " << gender << " " << age << " " << ano << " " << section << endl;
}

void University::TermBegin()
{
	cout << "请输入学校名称和地址: ";
	cin >> uname >> uaddress;
	string tname, tgender, ta, tb;
	int tage;
	cout << "请按照以下格式输入" << SNUM << "个学生的信息:" << endl;
	cout << "学号 姓名 性别 年龄 专业" << endl;
	for (int i = 0; i < SNUM; ++i) {
		cin >> ta >> tname >> tgender >> tage >> tb;
		Student Ts(tname, tgender, tage, ta, tb);
		S[i] = Ts;
		S[i].enroll();
	}
	cout << "请按照以下格式输入" << TNUM << "个教师的信息" << endl;
	cout << "工号 姓名 性别 年龄 学院" << endl;
	for (int i = 0; i < SNUM; ++i) {
		cin >> ta >> tname >> tgender >> tage >> tb;
		Teacher Tt(tname, tgender, tage, ta, tb);
		T[i] = Tt;
		T[i].recruit();
	}
	cout << "请按照以下格式输入" << TNUM << "个管理人员的信息" << endl;
	cout << "工号 姓名 性别 年龄 部门" << endl;
	for (int i = 0; i < SNUM; ++i) {
		cin >> ta >> tname >> tgender >> tage >> tb;
		Administrator Ta(tname, tgender, tage, ta, tb);
		A[i] = Ta;
		A[i].Employ();
	}
}

void University::showUniversity()
{
	cout << "该大学的基本信息如下:" << endl;
	cout << uname << " " << uaddress << endl;
	cout << "该大学的学生信息显示如下:" << endl;
	S[0].showStudent();
	S[1].showStudent();
	cout << "该大学的教师信息显示如下:" << endl;
	T[0].showTeacher();
	T[1].showTeacher();
	cout << "该大学的管理人员信息显示如下:" << endl;
	A[0].showAdministrator();
	A[1].showAdministrator();
}

int main()
{
	University u;
	u.TermBegin();
	u.showUniversity();
	return 0;
}
