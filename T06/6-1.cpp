/*
��1�������ܼ��
����һ����������ӣ�Box���࣬��������length������width�����ߣ�height��
�����ݳ�Ա�ͼ����ܳ�compute_perimeter()�������compute_area()�����compute_volume()�ȳ�Ա������
Ҫ���ܹ�ʹ�ù��캯�������ݳ�Ա���г�ʼ����������Ա�����ܹ������������ӵ��ܳ���������������
��2���������˵��
1.��ͷ�ļ��������࣬��Դ�ļ��ж�����ĳ�Ա�����Ͳ��Ժ�����ע��������ݳ�Ա�ͳ�Ա�����ķ���Ȩ�ޣ�
ʹ�����ع��캯���������ݳ�Ա��ʼ�����ṩ2�ֻ����ϳ�ʼ�����ݳ�Աlength��width��height�ķ�����
2.ע��������ع��캯���������Ͷ��巽ʽ��
����һ���������캯����ʹ�ÿ���ͨ��һ����������box1������ʼ����һ���¶�������box2����
3.�¶�������ݳ�Աlength��width��height�Ĵ�СΪԭ�����2����ע����Ŀ������캯���������Ͷ��巽ʽ��
*/
#include "6-1.h"
#include <iostream>

using namespace std;

Box::Box()
{
	length = 5;
	width = 3;
	height = 2;
}

Box::Box(double l, double w, double h) :length(l), width(w), height(h) {};

Box::Box(const Box& b)
{
	this->length = b.length * 2;
	this->width = b.width * 2;
	this->height = b.height * 2;
}

double Box::compute_perimeter()
{
	double perimeter = (length + width + height) * 4;
	return perimeter;
}

double Box::compute_area()
{
	double area = ((length * width) + (length * height) + (width * height)) * 2;
	return area;
}

double Box::compute_volume()
{
	double volume = length * height * width;
	return volume;
}

int main()
{
	double len, wid, hei;
	cout << "������ӵĳ����" << endl;
	cin >> len >> wid >> hei;
	Box b(len, wid, hei);
	cout << "�ܳ�: " << b.compute_perimeter() << endl;
	cout << "���: " << b.compute_area() << endl;
	cout << "���: " << b.compute_volume() << endl;
	cout << "�Ƿ���ÿ������캯���������*2��鿴��������? (��/y,��/n): ";
	char c;
	cin >> c;
	if (c == 'y') {
		Box b2(b);
		cout << "�ܳ�: " << b2.compute_perimeter() << endl;
		cout << "���: " << b2.compute_area() << endl;
		cout << "���: " << b2.compute_volume() << endl;
	}
	return 0;
}