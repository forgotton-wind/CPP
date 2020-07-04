#include <iostream>
#include <cmath>
#define PI 3.14

using namespace std;

class Shape {
public:
	void SetData();
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Circle :public Shape {
public:
	double Perimeter();
	double Area();
	Circle(int x) :r(x) {}
private:
	double r;
};

class Triangle :public Shape {
public:
	double Perimeter();
	double Area();
	Triangle(int x1, int x2, int x3) :a(x1), b(x2), c(x3) {}
private:
	double a, b, c;
};

class Rectangle :public Shape {
public:
	double Perimeter();
	double Area();
	Rectangle(int l, int w) :len(l), wid(w) {}
private:
	double len, wid;
};

class Trapezia :public Shape {
public:
	double Perimeter();
	double Area();
	Trapezia(int x1, int x2, int x3, int x4, int x5) :a(x1), b(x2), c(x3), d(x4), h(x5) {}
private:
	double a, b, c, d, h;
};

int main()
{
	Circle A(3);
	Triangle B(3,4,5);
	Rectangle C(4,3);
	Trapezia D(2, 5, 4, 5, 4);
	cout << "Բ�ΰ뾶Ϊ3, �ܳ�Ϊ" << A.Perimeter() << ", ���Ϊ" << A.Area() << endl;
	cout << "���������߳�Ϊ3, 4, 5, �ܳ�Ϊ" << B.Perimeter() << ", ���Ϊ" << B.Area() << endl;
	cout << "���γ�Ϊ4, ��Ϊ3, �ܳ�Ϊ" << C.Perimeter() << ", ���Ϊ" << C.Area() << endl;
	cout << "�����ϵ�Ϊ2, �µ�Ϊ5, ���Ϊ4��5, ��Ϊ5, �ܳ�Ϊ" << D.Perimeter() << ", ���Ϊ" << D.Area() << endl;
	return 0;
}

double Triangle::Perimeter()
{
	return(a + b + c);
}

double Triangle::Area()
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Circle::Perimeter()
{
	return 2 * PI * r;
}

double Circle::Area()
{
	return PI * r * r;
}

double Rectangle::Perimeter()
{
	return 2 * (len + wid);
}

double Rectangle::Area()
{
	return wid * len;
}

double Trapezia::Perimeter()
{
	return a + b + c + d;
}

double Trapezia::Area()
{
	return (a + b) * h / 2;
}