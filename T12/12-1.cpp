#include <iostream>

using namespace std;

class Figure {
public:
	Figure(int a) :sidenum(a) { cout << "This figure has " << sidenum << " sidenums" << endl; }
	Figure() {}
private:
	int sidenum;
};

class Quadrangle1 :virtual public Figure {
public:
	Quadrangle1(int a) :Figure(a) { cout << "This is a Quadrangle1" << endl; }
	Quadrangle1() { cout << "This is a Quadrangle1" << endl; }
};

class Parallelogram :virtual public Figure {
public:
	Parallelogram(int a) :Figure(a) { cout << "This is a Parallelogram" << endl; }
	Parallelogram() { cout << "This is a Parallelogram" << endl; }
};

class Quadrangle2 :virtual public Figure {
public:
	Quadrangle2(int a) :Figure(a) { cout << "This is a Quadrangle2" << endl; }
	Quadrangle2() { cout << "This is a Quadrangle2" << endl; }
};

class Rhombus :virtual public Quadrangle1, virtual public Parallelogram {
public:
	Rhombus(int a, double b) :Quadrangle1(a), Parallelogram(a), sidelength(b) {
		cout << "This is a Rhombus" << endl;
	}
private:
	double sidelength;
};

class Rectangle :virtual public Parallelogram, virtual public Quadrangle2 {
public:
	Rectangle(int a, double b) :Parallelogram(a), Quadrangle2(a), angle(b) {
		cout << "This is a Rectangle" << endl;
	}
private:
	double angle;
};

class Square :public Rhombus, public Rectangle {
public:
	Square(int a, double b, double c) :Rhombus(a, b), Rectangle(a, c), Figure(a) {
		cout << "The figure is a Square!" << endl;
		cout << "All angles are " << c << " degrees." << endl;
		cout << "The sidelength of the square is " << b << endl;
		cout << "The area of the square is " << b * b << endl;
	}
};

int main()
{
	Square s(4, 10, 90);
	return 0;
}