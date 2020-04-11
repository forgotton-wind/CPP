#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

double factorial(double);
void test(double);
int main()
{
	test(20);
	double num;
	cout << "\n请输入测试数据" << "(将计算1~此数的阶乘和): " << endl;
	cin >> num;
	test(num);
	return 0;
}

double factorial(double num)
{
	double fac = num;
	if (num == 1) return fac;
	fac *= factorial(--num);
	return fac;
}

void test(double j)
{
	double sum = 0;
	for (double i = 1; i <= j; i++) {
		double t = factorial(i);
		sum += factorial(i);
		cout << setw(2) << i << "的阶乘为" << setw(15) << t
			<< setw(10) << "1~" << setw(2) << i << "阶乘和为" << setw(15) << sum << endl;
	}
}