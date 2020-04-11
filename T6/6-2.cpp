/*
（1）程序功能简介
设计一个学生成绩管理程序，能够实现学生的学籍、课程和分数等信息的管理。
（2）程序设计说明
1.定义一个学生（Student）类，用来管理一个学生的学籍信息，
包括学号（sno）、姓名（sname）、性别（gender）、班级（grade）、课程（scourse）、成绩（sscore）等数据成员，
并提供一个成员函数student_show()显示学生的学号、姓名、性别、班级、课程、成绩等信息。
其中，课程（scourse）、分数（sscore）分别为课程（Course）类和分数（Score）类的对象；
2.定义一个课程（Course）类，用来管理一个学生所选的课程，包括课程号（cno）、课程名（cname）等数据成员，
并提供一个成员函数course_show()显示课程号（cno）、课程名（cname）等信息；
3.定义一个分数（Score）类，用来管理一个学生某门课程的分数，包括分数（score）等数据成员，
并提供一个成员函数score_show()显示分数（score）等信息；
4.注意数据成员的两种初始化方式，包括对象成员的构造、拷贝构造和析构的过程与优先级；
*/
#include "6-2.h"
#include <iostream>
#define MAX 10
using namespace std;

int main()
{
	Course C[MAX];
	Score S[MAX];
	Student A[MAX];
	char c = 'y';
	int i = 0;
	do {
		A[i].enroll();
		C[i].enroll();
		S[i].enroll(A[i], C[i]);
		A[i].enroll_2(C[i], S[i]);
		for (int j = 0; j <= i; ++j) {
			A[j].studentShow();
			//C[j].courseShow();
			//S[j].scoreShow();
		}
		cout << "是否继续输入下一组信息?(是/y,否/n): ";
		cin >> c;
		i++;
	} while (c == 'y');
	
	return 0;
}