#pragma once
#include <cmath>

//Distance::distance������Point�����Ԫ��Ա
class Distance {
public:
	double distance(class Point, class Point);
};

//Distance2����Point�����Ԫ��
class Distance2 {
public:
	double distance(class Point, class Point);
};

//distance������Point�����Ԫ����
class Point {
public:
	Point(double a = 0, double b = 0) :x(a), y(b) {}
	friend double distance(Point, Point);			//��Ԫ����
	friend double Distance::distance(Point, Point);	//��Ԫ��Ա
	friend class Distance2;							//��Ԫ��
private:
	double x;
	double y;
};
//��Ԫ����
double distance(Point A, Point B)
{
	double dx, dy, d;
	dx = A.x - B.x;
	dy = A.y - B.y;
	d = sqrt(dx * dx + dy * dy);
	return d;
}
//��Ԫ��Ա
double Distance::distance(Point A, Point B)
{
	double dx, dy, d;
	dx = A.x - B.x;
	dy = A.y - B.y;
	d = sqrt(dx * dx + dy * dy);
	return d;
}
//��Ԫ��
double Distance2::distance(Point A, Point B)
{
	double dx, dy, d;
	dx = A.x - B.x;
	dy = A.y - B.y;
	d = sqrt(dx * dx + dy * dy);
	return d;
}