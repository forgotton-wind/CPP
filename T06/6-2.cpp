/*
��1�������ܼ��
���һ��ѧ���ɼ���������ܹ�ʵ��ѧ����ѧ�����γ̺ͷ�������Ϣ�Ĺ���
��2���������˵��
1.����һ��ѧ����Student���࣬��������һ��ѧ����ѧ����Ϣ��
����ѧ�ţ�sno����������sname�����Ա�gender�����༶��grade�����γ̣�scourse�����ɼ���sscore�������ݳ�Ա��
���ṩһ����Ա����student_show()��ʾѧ����ѧ�š��������Ա𡢰༶���γ̡��ɼ�����Ϣ��
���У��γ̣�scourse����������sscore���ֱ�Ϊ�γ̣�Course����ͷ�����Score����Ķ���
2.����һ���γ̣�Course���࣬��������һ��ѧ����ѡ�Ŀγ̣������γ̺ţ�cno�����γ�����cname�������ݳ�Ա��
���ṩһ����Ա����course_show()��ʾ�γ̺ţ�cno�����γ�����cname������Ϣ��
3.����һ��������Score���࣬��������һ��ѧ��ĳ�ſγ̵ķ���������������score�������ݳ�Ա��
���ṩһ����Ա����score_show()��ʾ������score������Ϣ��
4.ע�����ݳ�Ա�����ֳ�ʼ����ʽ�����������Ա�Ĺ��졢��������������Ĺ��������ȼ���
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
		cout << "�Ƿ����������һ����Ϣ?(��/y,��/n): ";
		cin >> c;
		i++;
	} while (c == 'y');
	
	return 0;
}