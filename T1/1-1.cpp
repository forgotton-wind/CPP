#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::sqrt;

bool isprime(int);
void judge(void);
int main()
{
	cout << "100以内的素数如下:" << endl;
	for (int i = 2; i < 100; i++) {
		if (isprime(i)) {
			cout << setw(4) << i;
		}
	}
	cout << endl;
	judge();
	return 0;
}

bool isprime(int num)
{
	int i;
	for (i = 2; i < sqrt(num); i++) {
		if (num % i == 0) break;
	}
	if (i >= int(sqrt(num)) + 1) return true;
	else return false;
}

void judge(void)
{
	char c = 'y';
	do {
		cout << "请输入一个数: ";
		int num;
		cin >> num;
		if (isprime(num)) cout << "是素数！" << endl;
		else cout << "不是素数！" << endl;
		cout << "是否需要继续判断素数(y-是，n-否)？";
		cin >> c;
	} while (c == 'y');
}
