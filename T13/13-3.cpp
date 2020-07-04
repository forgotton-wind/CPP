#include <iostream>
#include <cmath>

using namespace std;

class Rational
{
public:
	Rational(int mm = 1, int nn = 1) :m(mm), n(nn) {}
	void print();
	void simple();
	friend  Rational  operator  +(Rational& a, Rational& b);		//�ӷ�
	friend  Rational  operator  -(Rational& a, Rational& b);		//����
	friend  Rational  operator  *(Rational& a, Rational& b);		//�˷�
	friend  Rational  operator  /(Rational& a, Rational& b);		//����
	Rational  operator  -();								//ȡ��
	Rational& operator  ++();								//r=++r1
	Rational  operator  ++(int);							//r=r1++
	Rational& operator  --();								//r=--r1
	Rational  operator  --(int);							//r =r1--
	operator double();
	friend ostream& operator<<(ostream& output, Rational& a);
	bool operator <(Rational&);
	friend bool operator ==(Rational&, Rational&);
private:
	int m, n;												//m����,n��ĸ
};

//Լ�ֻ���
void fractionReduction(int &m, int &n)
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
void form(int &m, int &n)
{
	if ((m > 0 && n < 0) || (m < 0 && n < 0)) {
		m = -m;
		n = -n;
	}
}

void Rational::print()
{
	cout << m << '/' << n;
}

Rational operator +(Rational& a, Rational& b)
{
	Rational temp;
	temp.m = a.n * b.m + a.m * b.n;
	temp.n = a.n * b.n;
	fractionReduction(temp.m, temp.n);
	form(temp.m, temp.n);
	return temp;
}

Rational operator -(Rational& a, Rational& b)
{
	Rational temp;
	temp.m = a.m * b.n - a.n * b.m;
	temp.n = a.n * b.n;
	fractionReduction(temp.m, temp.n);
	form(temp.m, temp.n);
	return temp;
}

Rational operator *(Rational& a, Rational& b)
{
	Rational temp;
	temp.m = a.m * b.m;
	temp.n = a.n * b.n;
	fractionReduction(temp.m, temp.n);
	form(temp.m, temp.n);
	return temp;
}

Rational operator /(Rational& a, Rational& b)
{
	Rational temp;
	temp.m = a.m * b.n;
	temp.n = a.n * b.m;
	fractionReduction(temp.m, temp.n);
	form(temp.m, temp.n);
	return temp;
}

Rational Rational::operator -()
{
	Rational temp;
	temp.m = -this->m;
	temp.n = this->n;
	fractionReduction(temp.m, temp.n);
	form(temp.m, temp.n);
	return temp;
}

Rational& Rational::operator ++()
{
	this->m = this->m + this->n;
	this->n = this->n;
	fractionReduction(this->m, this->n);
	form(this->m, this->n);
	return (*this);
}

Rational Rational::operator ++(int)
{
	Rational temp = *this;
	++(*this);
	fractionReduction(temp.m, temp.n);
	form(temp.m, temp.n);
	return temp;
}

Rational& Rational::operator --()
{
	this->m = this->m - this->n;
	this->n = this->n;
	fractionReduction(this->m, this->n);
	form(this->m, this->n);
	return (*this);
}

Rational Rational::operator --(int)
{
	Rational temp = *this;
	--(*this);
	fractionReduction(temp.m, temp.n);
	form(temp.m, temp.n);
	return temp;
}

int main() 
{
	Rational  A(2, 6), B(1, -2), C, Back;
	cout << "����A����Ϊ2����ĸΪ6������B����Ϊ1����ĸΪ-2" << endl << endl;
	C = -A;	cout << "C = -A = "; C.print();	cout << endl;
	C = A + B;	cout << "C = A + B = "; C.print();	cout << endl;
	C = A - B;	cout << "C = A - B = ";	C.print();	cout << endl;
	C = A * B;	cout << "C = A * B = "; C.print();	cout << endl;
	C = A / B;	cout << "C = A / B = "; C.print();	cout << endl;
	Back = A;		//��¼A��ֵ
	C = ++A;	cout << "C = ++A  A = ";	A.print();	cout << "  C = ";	C.print();	cout << endl;
	A = Back;		//��ԭA��ֵ
	C = A++;	cout << "C = A++  A = ";	A.print();  cout << "  C = ";	C.print();	cout << endl;
	Back = B;		//��¼B��ֵ
	C = ++B;	cout << "C = ++B  A = ";	B.print();	cout << "  C = ";	C.print();	cout << endl;
	B = Back;		//��ԭB��ֵ
	C = B++;	cout << "C = B++  A = ";	B.print();  cout << "  C = ";	C.print();	cout << endl;
	return 0;
}
