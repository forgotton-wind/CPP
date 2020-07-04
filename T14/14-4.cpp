#include <iostream>

using namespace std;

class People {
public:
	virtual void showAge() = 0;
private:
	int age;
};

class Baby :public People {
public:
	Baby(int b) :age(b) {}
	void showAge() { cout << "Age of Baby = " << age << endl; }
private:
	int age;
};

class Student :public Baby {
public:
	Student(int b, int s) :age(s), Baby(b) {}
	void showAge() { cout << "Age of Student = " << age << endl; }
private:
	int age;
};

class Adult :public Student {
public:
	Adult(int b, int s, int a) :age(a), Student(s, b) {}
	void showAge() { cout << "Age of Adult = " << age << endl; }
private:
	int age;
};

class Older :public Adult {
public:
	Older(int b, int s, int a, int o) :age(o), Adult(a, b, s) {}
	void showAge() { cout << "Age of Older = " << age << endl; }
private:
	int age;
};

int main()
{
	People* p[4];
	Baby B(2);
	Student S(2, 15);
	Adult A(2, 15, 27);
	Older O(2, 15, 27, 60);
	p[0] = &B; p[0]->showAge();
	p[1] = &S; p[1]->showAge();
	p[2] = &A; p[2]->showAge();
	p[3] = &O; p[3]->showAge();
	return 0;
}