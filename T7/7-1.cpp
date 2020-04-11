/*
（1）程序功能简介
设计一个点（Point）类，其中包括一对坐标数据成员、三个求两点之间距离的友元接口（包括友元函数、友元成员和友元类）
并用数据进行测试。
（2）程序设计说明
1.在头文件中声明类，在源文件中定义类的成员函数，采用构造函数进行对象的初始化；
2.首先，采用友元函数ExternalDistance()的方式实现友元接口；其次，采用友元成员的方式实现友元接口；
最后，采用友元类的方式实现友元接口。
3.对于友元成员和友元类两种实现方式，需要另外定义一个求解两点距离的Distance类，
将MemberDistance()作为该类的成员函数；
*/
#include "7-1.h"
#include <iostream>

using namespace std;

int main()
{
	double ax, ay, bx, by;
	cout << "请输入两个点的坐标(x和y之间以空格相隔)" << endl;
	cout << "A: ";
	cin >> ax >> ay;
	cout << "B: ";
	cin >> bx >> by;
	Point A(ax, ay), B(bx, by);
	cout << "友元函数实现 距离: " << distance(A, B) << endl;
	Distance D;
	cout << "友元成员实现 距离：" << D.distance(A, B) << endl;
	Distance2 D2;
	cout << "友元类实现   距离：" << D2.distance(A, B) << endl;
	return 0;
}
