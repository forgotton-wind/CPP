/*
��1�������ܼ��
���һ���㣨Point���࣬���а���һ���������ݳ�Ա������������֮��������Ԫ�ӿڣ�������Ԫ��������Ԫ��Ա����Ԫ�ࣩ
�������ݽ��в��ԡ�
��2���������˵��
1.��ͷ�ļ��������࣬��Դ�ļ��ж�����ĳ�Ա���������ù��캯�����ж���ĳ�ʼ����
2.���ȣ�������Ԫ����ExternalDistance()�ķ�ʽʵ����Ԫ�ӿڣ���Σ�������Ԫ��Ա�ķ�ʽʵ����Ԫ�ӿڣ�
��󣬲�����Ԫ��ķ�ʽʵ����Ԫ�ӿڡ�
3.������Ԫ��Ա����Ԫ������ʵ�ַ�ʽ����Ҫ���ⶨ��һ�������������Distance�࣬
��MemberDistance()��Ϊ����ĳ�Ա������
*/
#include "7-1.h"
#include <iostream>

using namespace std;

int main()
{
	double ax, ay, bx, by;
	cout << "�����������������(x��y֮���Կո����)" << endl;
	cout << "A: ";
	cin >> ax >> ay;
	cout << "B: ";
	cin >> bx >> by;
	Point A(ax, ay), B(bx, by);
	cout << "��Ԫ����ʵ�� ����: " << distance(A, B) << endl;
	Distance D;
	cout << "��Ԫ��Աʵ�� ���룺" << D.distance(A, B) << endl;
	Distance2 D2;
	cout << "��Ԫ��ʵ��   ���룺" << D2.distance(A, B) << endl;
	return 0;
}
