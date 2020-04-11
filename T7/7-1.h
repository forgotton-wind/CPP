#pragma once
#include <cmath>

//Distance::distance函数是Point类的友元成员
class Distance {
public:
	double distance(class Point, class Point);
};

//Distance2类是Point类的友元类
class Distance2 {
public:
	double distance(class Point, class Point);
};

//distance函数是Point类的友元函数
class Point {
public:
	Point(double a = 0, double b = 0) :x(a), y(b) {}
	friend double distance(Point, Point);			//友元函数
	friend double Distance::distance(Point, Point);	//友元成员
	friend class Distance2;							//友元类
private:
	double x;
	double y;
};
//友元函数
double distance(Point A, Point B)
{
	double dx, dy, d;
	dx = A.x - B.x;
	dy = A.y - B.y;
	d = sqrt(dx * dx + dy * dy);
	return d;
}
//友元成员
double Distance::distance(Point A, Point B)
{
	double dx, dy, d;
	dx = A.x - B.x;
	dy = A.y - B.y;
	d = sqrt(dx * dx + dy * dy);
	return d;
}
//友元类
double Distance2::distance(Point A, Point B)
{
	double dx, dy, d;
	dx = A.x - B.x;
	dy = A.y - B.y;
	d = sqrt(dx * dx + dy * dy);
	return d;
}