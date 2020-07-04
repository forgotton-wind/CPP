#include <iostream>
#include <cmath>

using namespace std;

class Rational
{
public:
	Rational(int mm = 1, int nn = 1) :m(mm), n(nn) {}
	void print();
	void simple();
	friend  Rational  operator  +(Rational& a, Rational& b);		//加法
	friend  Rational  operator  -(Rational& a, Rational& b);		//减法
	friend  Rational  operator  *(Rational& a, Rational& b);		//乘法
	friend  Rational  operator  /(Rational& a, Rational& b);		//除法
	Rational  operator  -();								//取反
	Rational& operator  ++();								//r=++r1
	Rational  operator  ++(int);							//r=r1++
	Rational& operator  --();								//r=--r1
	Rational  operator  --(int);							//r =r1--
	operator double();
	friend ostream& operator<<(ostream& output, Rational& a);
	bool operator <(Rational&);
	friend bool operator ==(Rational&, Rational&);
private:
	int m, n;												//m分子,n分母
};

//约分化简
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

//负号放前面
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
	cout << "设置A分子为2，分母为6；设置B分子为1，分母为-2" << endl << endl;
	C = -A;	cout << "C = -A = "; C.print();	cout << endl;
	C = A + B;	cout << "C = A + B = "; C.print();	cout << endl;
	C = A - B;	cout << "C = A - B = ";	C.print();	cout << endl;
	C = A * B;	cout << "C = A * B = "; C.print();	cout << endl;
	C = A / B;	cout << "C = A / B = "; C.print();	cout << endl;
	Back = A;		//记录A的值
	C = ++A;	cout << "C = ++A  A = ";	A.print();	cout << "  C = ";	C.print();	cout << endl;
	A = Back;		//还原A的值
	C = A++;	cout << "C = A++  A = ";	A.print();  cout << "  C = ";	C.print();	cout << endl;
	Back = B;		//记录B的值
	C = ++B;	cout << "C = ++B  A = ";	B.print();	cout << "  C = ";	C.print();	cout << endl;
	B = Back;		//还原B的值
	C = B++;	cout << "C = B++  A = ";	B.print();  cout << "  C = ";	C.print();	cout << endl;
	return 0;
}
