#pragma once

class Box {
public:
	Box();
	Box(double, double, double);
	Box(const Box& b);
	double compute_perimeter();
	double compute_area();
	double compute_volume();
private:
	double length;
	double width;
	double height;
};