#include <iostream>
#include <cmath>

using namespace std;

bool isNar(int);
int main()
{
	int num;
	char ch;
	cout << "ˮ�ɻ�����:" << endl;
	for (int i = 100; i < 1000; i++) {
		if (isNar(i)) cout << i << '\t';
	} 
	cout << endl;
	do {
		cout << "Please input a number (100<number<999)" << endl;
		cin >> num;
		if (isNar(num)) {
			cout << num << "��ˮ�ɻ���" << endl;
		}
		else cout << num << "����ˮ�ɻ���" << endl;
		cout << "�Ƿ��������-y,��-n" << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;
}

bool isNar(int num)
{
	int a, b, c;
	a = num / 100;
	b = (num / 10) % 10;
	c = num % 10;
	if (pow(a, 3) + pow(b, 3) + pow(c, 3) == num) {
		return true;
	}
	else return false;
}