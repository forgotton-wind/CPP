/*
（1）程序功能简介
定义一个立方体盒子（Box）类，包括长（length）、宽（width）、高（height）
等数据成员和计算周长compute_perimeter()、表面积compute_area()、体积compute_volume()等成员函数。
要求：能够使用构造函数对数据成员进行初始化，三个成员函数能够输出立方体盒子的周长、表面积和体积。
（2）程序设计说明
1.在头文件中声明类，在源文件中定义类的成员函数和测试函数，注意类的数据成员和成员函数的访问权限；
使用重载构造函数进行数据成员初始化，提供2种或以上初始化数据成员length、width、height的方法，
2.注意类的重载构造函数的声明和定义方式；
定义一个拷贝构造函数，使得可以通过一个对象（例如box1）来初始化另一个新对象（例如box2），
3.新对象的数据成员length、width、height的大小为原对象的2倍，注意类的拷贝构造函数的声明和定义方式；
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
	cout << "输入盒子的长宽高" << endl;
	cin >> len >> wid >> hei;
	Box b(len, wid, hei);
	cout << "周长: " << b.compute_perimeter() << endl;
	cout << "面积: " << b.compute_area() << endl;
	cout << "体积: " << b.compute_volume() << endl;
	cout << "是否调用拷贝构造函数将长宽高*2后查看各项属性? (是/y,否/n): ";
	char c;
	cin >> c;
	if (c == 'y') {
		Box b2(b);
		cout << "周长: " << b2.compute_perimeter() << endl;
		cout << "面积: " << b2.compute_area() << endl;
		cout << "体积: " << b2.compute_volume() << endl;
	}
	return 0;
}