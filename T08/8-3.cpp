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
	void enroll() { cout << "һ��ѧ����ļ���!" << endl; }
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
	void recruit() { cout << "һ����ʦ��ļ���!" << endl; }
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
	void Employ() { cout << "һ��������Ա��ļ���!" << endl; }
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
	cout << "������ѧУ���ƺ͵�ַ: ";
	cin >> uname >> uaddress;
	string tname, tgender, ta, tb;
	int tage;
	cout << "�밴�����¸�ʽ����" << SNUM << "��ѧ������Ϣ:" << endl;
	cout << "ѧ�� ���� �Ա� ���� רҵ" << endl;
	for (int i = 0; i < SNUM; ++i) {
		cin >> ta >> tname >> tgender >> tage >> tb;
		Student Ts(tname, tgender, tage, ta, tb);
		S[i] = Ts;
		S[i].enroll();
	}
	cout << "�밴�����¸�ʽ����" << TNUM << "����ʦ����Ϣ" << endl;
	cout << "���� ���� �Ա� ���� ѧԺ" << endl;
	for (int i = 0; i < SNUM; ++i) {
		cin >> ta >> tname >> tgender >> tage >> tb;
		Teacher Tt(tname, tgender, tage, ta, tb);
		T[i] = Tt;
		T[i].recruit();
	}
	cout << "�밴�����¸�ʽ����" << TNUM << "��������Ա����Ϣ" << endl;
	cout << "���� ���� �Ա� ���� ����" << endl;
	for (int i = 0; i < SNUM; ++i) {
		cin >> ta >> tname >> tgender >> tage >> tb;
		Administrator Ta(tname, tgender, tage, ta, tb);
		A[i] = Ta;
		A[i].Employ();
	}
}

void University::showUniversity()
{
	cout << "�ô�ѧ�Ļ�����Ϣ����:" << endl;
	cout << uname << " " << uaddress << endl;
	cout << "�ô�ѧ��ѧ����Ϣ��ʾ����:" << endl;
	S[0].showStudent();
	S[1].showStudent();
	cout << "�ô�ѧ�Ľ�ʦ��Ϣ��ʾ����:" << endl;
	T[0].showTeacher();
	T[1].showTeacher();
	cout << "�ô�ѧ�Ĺ�����Ա��Ϣ��ʾ����:" << endl;
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
