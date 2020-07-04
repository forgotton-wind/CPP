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
	cout << "100���ڵ���������:" << endl;
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
		cout << "������һ����: ";
		int num;
		cin >> num;
		if (isprime(num)) cout << "��������" << endl;
		else cout << "����������" << endl;
		cout << "�Ƿ���Ҫ�����ж�����(y-�ǣ�n-��)��";
		cin >> c;
	} while (c == 'y');
}
