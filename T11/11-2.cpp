#include <iostream>
using namespace std;

//�����������·��������
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

//��̳н��·������������
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
	cout << "---------------���������---------------" << endl;
	cout << "��B·��: ";
	d.B::show();
	cout << "��C·��: ";
	d.C::show();
	cout << "�����������·��������ʱ�����������ռ�ռ��СΪ: " << sizeof(d) << endl;
	cout << "����: B, C�и�����A��һ������, A��3��int, ռ12�ֽڣ�����ռ�����飬�ܼ�24���ֽ�" << endl;
	D2 d2(1, 2, 3, 4, 5, 6);
	cout << "---------------��̳�---------------" << endl;
	cout << "��B·��: ";
	d2.B2::show();
	cout << "��C·��: ";
	d2.C2::show();
	cout << "ֱ�ӿ�A: ";
	d2.show();
	cout << "��̳н��·��������ʱ�����������ռ�ռ��СΪ: " << sizeof(d2) << endl;
	cout << "����: B, C��̳�A, ֻ��һ��A���ݳ�Ա, ��3��int, ռ12�ֽڡ�B, C�и��Դ���һ����ָ��, ��ռ4�ֽ�, �ܼ�20�ֽ�" << endl;
	return 0;
}