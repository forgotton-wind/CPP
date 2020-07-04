/*
（1）程序功能简介
实现一个具有计算器功能的程序。
（2）程序设计说明
用户根据程序提示输入数字，选择要进行的运算，可以进行加、减、乘、除、平方、求模、求方根等运算；
针对加、减、乘、除、平方、求模、求方根操作，每种操作设计一个成员函数实现相应功能；
*/

#include <iostream>
#include <cmath>

using namespace std;

class calculator {
public:
	double add(double a, double b);
	double sub(double a, double b);
	double mul(double a, double b);
	double div(double a, double b);
	double square(double a);
	double modulus(double a);
	double squareRoot(double a);
};

double calculator::add(double a, double b)
{
	double res = a + b;
	cout << a << "+" << b << "=" << res << endl;
	return res;
}

double calculator::sub(double a, double b)
{
	double res = a - b;
	cout << a << "-" << b << "=" << res << endl;
	return res;
}

double calculator::mul(double a, double b)
{
	double res = a * b;
	cout << a << "*" << b << "=" << res << endl;
	return res;

}

double calculator::div(double a, double b)
{
	double res = a / b;
	cout << a << "/" << b << "=" << res << endl;
	return res;
}

double calculator::square(double a)
{
	double res = a * a;
	cout << a << "*" << a << "=" << res << endl;
	return res;
}

double calculator::modulus(double a)
{
	double res = fabs(a);
	cout << '|' << a << '|' << "=" << res << endl;
	return res;
}

double calculator::squareRoot(double a)
{
	double res = sqrt(a);
	cout << a << '^' << "(1/2)" << '=' << res << endl;
 	return res;
}


int main()
{
	calculator A;
	cout << "简易计算器" << endl;
	cout << "运算符有:" << endl;
	cout << "加法+ " << "减法- " << "乘法* " << "除法/ " << "平方^ " << "模| " << "开方# " << endl;
	char c = 'y';
	double a, b;
	char op;
restart:
	cout << "请输入操作数" << endl;
	cin >> a;
	while (c == 'y') {
		cout << "请输入操作符" << endl;
		cin >> op;
		switch (op)
		{
		case '+':
			cout << "请输入操作数" << endl;
			cin >> b;
			cout << "运算结果为" << endl;
			a = A.add(a, b);
			break;
		case '-':
			cout << "请输入操作数" << endl;
			cin >> b;
			cout << "运算结果为" << endl;
			a = A.sub(a, b);
			break;
		case '*':
			cout << "请输入操作数" << endl;
			cin >> b;
			cout << "运算结果为" << endl;
			a = A.mul(a, b);
			break;
		case '/':
			cout << "请输入操作数" << endl;
			cin >> b;
			if (b == 0) {
				cout << "除数不能为0" << endl;
				goto restart;
			}
			else {
				cout << "运算结果为" << endl;
				a = A.div(a, b);
			}
			break;
		case '^':
			cout << "运算结果为" << endl;
			a = A.square(a);
			break;
		case '|':
			cout << "运算结果为" << endl;
			a = A.modulus(a);
			break;
		case '#':
			if (a >= 0) {
				cout << "运算结果为" << endl;
				a = A.squareRoot(a);
			}
			else {
				cout << "负数不能开根号" << endl;
				goto restart;
			}
			break;
		default:
			cout << "ERROR!!!";
			break;
		}
		cout << "是否继续？是-y,否-n" << endl;
		cin >> c;
	}
	return 0;
}