#include <iostream>

using namespace std;

class Student {
public:
	virtual void calTuition() { cout << "����ѧ��ѧ��" << endl; }
};

class Master : public Student {
public:
	void calTuition() { cout << "����˶ʿ��ѧ��" << endl; }
};

class Doctor : public Student {
public:
	void calTuition() { cout << "���㲩ʿ��ѧ��" << endl; }
};

void fn(Student& x) { x.calTuition(); }

int main()
{
	Student s;   
	Master m;  
	Doctor d;
	fn(s);          //����һ��ѧ��s��ѧ��
	fn(m);          //����һ��˶ʿ��m��ѧ��
	fn(d);          //����һ�²�ʿ��d��ѧ��
	return 0;
}