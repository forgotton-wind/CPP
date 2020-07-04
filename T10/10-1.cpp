#include <iostream>

using namespace std;

class Wood {
public:
	void useWood() { cout << "使用木材量: " << wood_amount << endl; }
	Wood(double w) :wood_amount(w) { useWood(); }
private:
	double wood_amount;
};

class Metal {
public:
	void useMetal() { cout << "使用金属量: " << metal_amount << endl; }
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
	void canSit() { cout << "沙发重量为: " << sofa_weight << ", 可以坐下的人数为: " << sofa_capacity << endl; }
	Sofa(double w, double m, double wei, double ca) : Furniture(w, m), sofa_weight(wei), sofa_capacity(ca) { canSit(); }
private:
	double sofa_weight;
	double sofa_capacity;
};

class Bed :public Furniture {
public:
	void canLie() { cout << "床重量为: " << bed_weight << ", 可以躺下的人数为: " << bed_capacity << endl; }
	Bed(double w, double m, double wei, double ca) :Furniture(w, m), bed_weight(wei), bed_capacity(ca) { canLie(); }
private:
	double bed_weight;
	double bed_capacity;
};

class SofaBed :public Sofa, public Bed {
public:
	void itsFuction(double w, double m, double wei, double ca) {
		cout << "-------------------------------------------" << endl;
		cout << "沙发床共计使用木头量为: " << w << ", 共计使用金属量: " << m << endl;
		cout << "沙发床总质量为:" << wei << ", 总容纳人数为: " << ca << endl;
	}
	SofaBed(double w1, double m1, double wei1, double ca1, double w2, double m2, double wei2, double ca2) :
		Sofa(w1, m1, wei1, ca1), Bed(w2, m2, wei2, ca2) { itsFuction(w1+w2, m1+m2, wei1+wei2, ca1+ca2); }
};

int main()
{
	SofaBed(100, 20, 200, 5, 300, 30, 700, 3);
	return 0;
}