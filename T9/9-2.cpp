#include <iostream>

using namespace std;

class Base {
public:
	int x;
	Base(int tx, int ty, int tz) :x(tx), y(ty), z(tz) {}
	void showData() { cout << "Base::x = " << x << "  " << "Base::y = " << y << "  " << "Base::z = " << z << endl; }
protected:
	int y;
private:
	int z;
};

class Derived : public Base {
public:
	int dx;
	Derived(int tx, int ty, int tz, int bx, int by, int bz) :dx(tx), dy(ty), dz(tz), Base(bx, by, bz) {}
	void showData() { cout << "Derived::dx = " << dx << "  " << "Derived::dy = " << dy << "  " << "Derived::dz = " << dz << endl; }
protected:
	int dy;
private:
	int dz;
};

int main()
{
	Base b(1, 2, 3);
	cout << "公有派生类对象赋值给基类对象前，基类对象的数据状态如下：" << endl;
	b.showData();

	Derived d(14, 15, 16, 11, 12, 13);
	b = d;
	cout << "公有派生类对象赋值给基类对象后，基类对象的数据状态如下：" << endl;
	b.showData();

	Base& rb = d;
	cout << "公有派生类对象初始化基类对象引用后，基类对象的数据状态如下：" << endl;
	rb.showData();

	Base* pb = &d;
	cout << "公有派生类对象地址赋值给基类对象指针后，基类对象的数据状态如下：" << endl;
	pb->showData();
	return 0;
}