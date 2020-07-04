#include <iostream>
using namespace std;

//作用域规则解决路径二义性
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

class B :public A {
public:
	B(int ta, int tb, int tc) :A(ta, tb, tc) {}
};

class C :public A {
public:
	C(int ta, int tb, int tc) :A(ta, tb, tc) {}
};

class D :public B, public C {
public:
	D(int ta, int tb, int tc, int ta2, int tb2, int tc2) :B(ta, tb, tc), C(ta2, tb2, tc2) {}
};

//虚继承解决路径二义性问题
class A2 {
public:
	int a;
	A2(int ta, int tb, int tc) :a(ta), b(tb), c(tc) {}
	void show() { cout << "A::a = " << a << "  A::b = " << b << "  A::c = " << c << endl; }
protected:
	int b;
private:
	int c;
};

class B2 :virtual public A2 {
public:
	B2(int ta, int tb, int tc) :A2(ta, tb, tc) {}
};

class C2 :virtual public A2 {
public:
	C2(int ta, int tb, int tc) :A2(ta, tb, tc) {}
};

class D2 :public B2, public C2 {
public:
	D2(int ta, int tb, int tc, int ta2, int tb2, int tc2) :B2(ta, tb, tc), C2(ta2, tb2, tc2), A2(ta, tb, tc) {}
};

int main()
{
	D d(1, 2, 3, 4, 5, 6);
	cout << "---------------作用域规则---------------" << endl;
	cout << "从B路径: ";
	d.B::show();
	cout << "从C路径: ";
	d.C::show();
	cout << "作用域规则解决路径二义性时，派生类对象占空间大小为: " << sizeof(d) << endl;
	cout << "分析: B, C中各存在A的一个副本, A有3个int, 占12字节，共计占用两组，总计24个字节" << endl;
	D2 d2(1, 2, 3, 4, 5, 6);
	cout << "---------------虚继承---------------" << endl;
	cout << "从B路径: ";
	d2.B2::show();
	cout << "从C路径: ";
	d2.C2::show();
	cout << "直接看A: ";
	d2.show();
	cout << "虚继承解决路径二义性时，派生类对象占空间大小为: " << sizeof(d2) << endl;
	cout << "分析: B, C虚继承A, 只有一份A数据成员, 有3个int, 占12字节。B, C中各自存在一个虚指针, 各占4字节, 总计20字节" << endl;
	return 0;
}