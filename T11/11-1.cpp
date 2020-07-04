#include <iostream>

using namespace std;

class A {
public:
	int a;
	A(int ta, int tb, int tc) :a(ta), b(tb), c(tc) {}
	void show() { cout << "A::a = " << a << "  A::b = " << b << "  A::c = " << c << endl; }
protected:
	int b;
private:
	int c;
};

class B {
public:
	int a;
	B(int ta, int tb, int tc) :a(ta), b(tb), c(tc) {}
	void show() { cout << "B::a = " << a << "  B::b = " << b << "  B::c = " << c << endl; }
protected:
	int b;
private:
	int c;
};

class C :public A, public B {
public:
	C(int a1, int b1, int c1, int a2, int b2, int c2) :A(a1, b1, c1), B(a2, b2, c2) {}
};

int main()
{
	C c(1, 2, 3, 4, 5, 6);
	c.A::show();
	c.B::show();
	return 0;
}