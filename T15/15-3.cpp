#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Fraction {
public:
	friend ostream& operator<<(ostream& os, Fraction& F);
	friend istream& operator>>(istream& is, Fraction& F);
private:
	int m, n;						//m���ӣ�n��ĸ
};

ostream& operator<<(ostream& os, Fraction& F) {
	void fractionReduction(int& m, int& n);
	void form(int& m, int& n);
	fractionReduction(F.m, F.n);
	form(F.m, F.n);
	os << F.m << "/" << F.n;
	return os;
}

istream& operator>>(istream& is, Fraction& F) {
	is >> F.m >> F.n;
	return is;
}

//Լ�ֻ���
void fractionReduction(int& m, int& n)
{
	int min = abs(m < n ? m : n);
	int i;
	do {
		for (i = min; i >= 2; --i) {
			if (m % i == 0 && n % i == 0) {
				m = m / i;
				n = n / i;
				break;
			}
		}
	} while (i != 1);
}

//���ŷ�ǰ��
void form(int& m, int& n)
{
	if ((m > 0 && n < 0) || (m < 0 && n < 0)) {
		m = -m;
		n = -n;
	}
}

int main()
{
	Fraction F;
	cout << "��������ӷ�ĸ" << endl;
	cin >> F;
	cout << F;
	return 0;
}