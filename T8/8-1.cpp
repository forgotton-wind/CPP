#include <iostream>

using namespace std;

class CBase {
private:
	int x;
	void showx() { cout << "CBase::x=" << x << endl; }
protected:
	int y;
	void showy() { cout << "CBase::y=" << y << endl; }
public:
	int z;
	void showz() { cout << "CBase::z=" << z << endl; }
	CBase(int t1, int t2, int t3) :x(t1), y(t2), z(t3) {}
	void showbasex() { showx(); }
};
class CDeriveA :private CBase {
private:
	int ax;
	void showax() { showbasex(); cout << "CDeriveA::ax=" << ax << endl; }
protected:
	int ay;
	void showay() { showy(); cout << "CDeriveA::ay=" << ay << endl; }
public:
	int az;
	void showaz() { showz(); cout << "CDeriveA::az=" << az << endl; }
	CDeriveA(int t1, int t2, int t3, int t4, int t5, int t6) :CBase(t1, t2, t3), ax(t4), ay(t5), az(t6) {}
	void showAxandBasexfromOuterA() { showax(); }
	void showAyandBaseyfromOuterA() { showay(); }
};
class CDeriveB :protected CBase {
private:
	int bx;
	void showbx() { showbasex(); cout << "CDeriveB::bx=" << bx << endl; }
protected:
	int by;
	void showby() { showy(); cout << "CDeriveB::by=" << by << endl; }
public:
	int bz;
	void showbz() { showz(); cout << "CDeriveB::bz=" << bz << endl; }
	CDeriveB(int t1, int t2, int t3, int t4, int t5, int t6) :CBase(t1, t2, t3), bx(t4), by(t5), bz(t6) {}
	void showBxandBasexfromOuterB() { showbx(); }
	void showByandBaseyfromOuterB() { showby(); }
};
class CDeriveC :public CBase {
private:
	int cx;
	void showcx() { showbasex(); cout << "CDeriveC::cx=" << cx << endl; }
protected:
	int cy;
	void showcy() { showy(); cout << "CDeriveC::cy=" << cy << endl; }
public:
	int cz;
	void showcz() {showz(); cout << "CDeriveC::cz=" << cz << endl; }
	CDeriveC(int t1, int t2, int t3, int t4, int t5, int t6) :CBase(t1, t2, t3), cx(t4), cy(t5), cz(t6) {}
	void showCxandBasexfromOuterC() { showcx(); }
	void showCyandBaseyfromOuterC() { showcy(); }
};
void main() {
	CDeriveA ca(11, 12, 13, 14, 15, 16);
	//ca.showx();
	//ca.showy();
	//ca.showz();
	//ca.showax();
	ca.showAxandBasexfromOuterA();
	//ca.showay();
	ca.showAyandBaseyfromOuterA();
	ca.showaz();

	CDeriveB cb(21, 22, 23, 24, 25, 26);
	//cb.showx();
	//cb.showy();
	//cb.showz();
	//cb.showbx();
	cb.showBxandBasexfromOuterB();
	//cb.showby();
	cb.showByandBaseyfromOuterB();
	cb.showbz();

	CDeriveC cc(31, 32, 33, 34, 35, 36);
	//cc.showx();
	//cc.showy();
	//cc.showcx();
	//cc.showcy();
	cc.showCxandBasexfromOuterC();
	cc.showCyandBaseyfromOuterC();
	cc.showcz();
}