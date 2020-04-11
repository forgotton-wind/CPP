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
	cout << "课程号: ";
	cin >> cno;
	cout << "课程名: ";
	cin >> cname;
}

void Course::courseShow()
{
	cout << "课程信息: " << cno << " " << cname << endl;
}

void Score::enroll(class Student A, class Course C)
{
	cout << "得分: ";
	cin >> score;
	strcpy(this->cname, C.cname);
	strcpy(this->sname, A.sname);
}

void Score::scoreShow()
{
	cout << "分数信息: " << sname << " " << cname << " " << score << endl;
}

void Student::enroll()
{
	cout << "请输入学生信息" << endl;
	cout << "学号: ";
	cin >> sno;
	cout << "姓名: ";
	cin >> sname;
	cout << "性别: ";
	cin >> gender;
	cout << "班级: ";
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
	cout << "学生信息: " << sno << " " << sname << " " << gender << " " << grade << " "
		<< scourse.cno << " " << scourse.cname << " " << sscore.score << endl;
}
