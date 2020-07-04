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
	cout << "�������������ֵ���������ǰ��������������״̬���£�" << endl;
	b.showData();

	Derived d(14, 15, 16, 11, 12, 13);
	b = d;
	cout << "�������������ֵ���������󣬻�����������״̬���£�" << endl;
	b.showData();

	Base& rb = d;
	cout << "��������������ʼ������������ú󣬻�����������״̬���£�" << endl;
	rb.showData();

	Base* pb = &d;
	cout << "��������������ַ��ֵ���������ָ��󣬻�����������״̬���£�" << endl;
	pb->showData();
	return 0;
}