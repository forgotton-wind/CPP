/*
��1�������ܼ��
���һ��ѧ���ɼ���������ܹ�ʵ��ѧ����ѧ�����γ̺ͷ�������Ϣ�Ĺ���
��2���������˵��
1.����һ��ѧ����Student���࣬��������һ��ѧ����ѧ����Ϣ��
����ѧ�ţ�sno����������sname�����Ա�gender�����༶��grade�������ݳ�Ա��
���ṩһ����Ա����student_show()��ʾѧ����ѧ�š��������Ա𡢰༶���γ̡��ɼ�����Ϣ��
һ����Ա����course_show()��ʾ�γ̵Ŀγ̺š��γ�������Ϣ��һ����Ա����score_show()��ʾ��������Ϣ��
���У�course_show()��score_show()�ֱ�����Ϊ�γ̣�Course����ͷ�����Score�������Ԫ��
���߽�Student������Ϊ�γ̣�Course����ͷ�����Score�������Ԫ��
2.����һ���γ̣�Course���࣬��������һ��ѧ����ѡ�Ŀγ̣������γ̺ţ�cno�����γ�����cname�������ݳ�Ա��
���ṩһ�����캯����ʼ���γ̺ţ�cno�����γ�����cname������Ϣ��
3.����һ��������Score���࣬��������һ��ѧ��ĳ�ſγ̵ķ���������������score�������ݳ�Ա��
���ṩһ�����캯����ʼ��������score������Ϣ
*/
#include "7-2.h"
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
		cout << "�Ƿ����������һ����Ϣ?(��/y,��/n): ";
		cin >> c;
		i++;
	} while (c == 'y');

	return 0;
}