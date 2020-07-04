#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Student;
class Score;
class Course {
public:
	void courseShow();
	Course(char*, char*);
	Course() {}
	void enroll();
	friend class Student;
	friend class Score;
private:
	char cno[20];
	char cname[20];
};

class Score {
public:
	void scoreShow();
	Score() {}
	Score(char*, char*, double);
	void enroll(class Student A, class Course C);
	friend class Student;
private:
	char sname[15];
	char cname[20];
	double score;
};

class Student {
public:
	void studentShow();
	Student(char*, char*, char*, char*, class Course, class Score);
	Student() {}
	void enroll();
	void enroll_2(class Course, class Score);
	friend class Score;
private:
	char sno[15];
	char sname[15];
	char gender[10];
	char grade[20];
	class Course scourse;
	class Score sscore;
};

Student::Student(char* sno, char* sname, char* gender, char* grade, Course course, Score score)
{
	strcpy(this->sno, sno);
	strcpy(this->sname, sname);
	strcpy(this->gender, gender);
	strcpy(this->grade, grade);
	scourse = course;
	sscore = score;
}

Course::Course(char* cno, char* cname)
{
	strcpy(this->cno, cno);
	strcpy(this->cname, cname);
}

Score::Score(char* sname, char* cname, double score)
{
	strcpy(this->sname, sname);
	strcpy(this->cname, cname);
	this->score = score;
}

void Course::enroll()
{
	cout << "�γ̺�: ";
	cin >> cno;
	cout << "�γ���: ";
	cin >> cname;
}

void Course::courseShow()
{
	cout << "�γ���Ϣ: " << cno << " " << cname << endl;
}

void Score::enroll(class Student A, class Course C)
{
	cout << "�÷�: ";
	cin >> score;
	strcpy(this->cname, C.cname);
	strcpy(this->sname, A.sname);
}

void Score::scoreShow()
{
	cout << "������Ϣ: " << sname << " " << cname << " " << score << endl;
}

void Student::enroll()
{
	cout << "������ѧ����Ϣ" << endl;
	cout << "ѧ��: ";
	cin >> sno;
	cout << "����: ";
	cin >> sname;
	cout << "�Ա�: ";
	cin >> gender;
	cout << "�༶: ";
	cin >> grade;
}

void Student::enroll_2(class Course C, class Score S)
{
	strcpy(scourse.cno, C.cno);
	strcpy(scourse.cname, C.cname);
	sscore.score = S.score;
}

void Student::studentShow()
{
	cout << "ѧ����Ϣ: " << sno << " " << sname << " " << gender << " " << grade << " "
		<< scourse.cno << " " << scourse.cname << " " << sscore.score << endl;
}
