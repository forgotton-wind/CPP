#include <iostream>

using namespace std;

class Wood {
public:
	void useWood() { cout << "ʹ��ľ����: " << wood_amount << endl; }
	Wood(double w) :wood_amount(w) { useWood(); }
private:
	double wood_amount;
};

class Metal {
public:
	void useMetal() { cout << "ʹ�ý�����: " << metal_amount << endl; }
	Metal(double m) :metal_amount(m) { useMetal(); }
private:
	double metal_amount;
};

class Furniture :public Wood, public Metal {
public:
	Furniture(double w, double m) :Wood(w), Metal(m) {}
};

class Sofa :public Furniture {
public:
	void canSit() { cout << "ɳ������Ϊ: " << sofa_weight << ", �������µ�����Ϊ: " << sofa_capacity << endl; }
	Sofa(double w, double m, double wei, double ca) : Furniture(w, m), sofa_weight(wei), sofa_capacity(ca) { canSit(); }
private:
	double sofa_weight;
	double sofa_capacity;
};

class Bed :public Furniture {
public:
	void canLie() { cout << "������Ϊ: " << bed_weight << ", �������µ�����Ϊ: " << bed_capacity << endl; }
	Bed(double w, double m, double wei, double ca) :Furniture(w, m), bed_weight(wei), bed_capacity(ca) { canLie(); }
private:
	double bed_weight;
	double bed_capacity;
};

class SofaBed :public Sofa, public Bed {
public:
	void itsFuction(double w, double m, double wei, double ca) {
		cout << "-------------------------------------------" << endl;
		cout << "ɳ��������ʹ��ľͷ��Ϊ: " << w << ", ����ʹ�ý�����: " << m << endl;
		cout << "ɳ����������Ϊ:" << wei << ", ����������Ϊ: " << ca << endl;
	}
	SofaBed(double w1, double m1, double wei1, double ca1, double w2, double m2, double wei2, double ca2) :
		Sofa(w1, m1, wei1, ca1), Bed(w2, m2, wei2, ca2) { itsFuction(w1+w2, m1+m2, wei1+wei2, ca1+ca2); }
};

int main()
{
	SofaBed(100, 20, 200, 5, 300, 30, 700, 3);
	return 0;
}