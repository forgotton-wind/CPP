#include <iostream>
using namespace std;

void move(char, char);
void hanoi(int, char, char, char);
int main()
{
	int n;
	char ch;
	do {
		cout << "ººÅµËþÎÊÌâ" << endl << "Please input the number of diskes: ";
		cin >> n;
		cout << "The step to move " << n << " diskes:" << endl;
		hanoi(n, '1', '2', '3');
		cout << "Do you want to go on? (y for yes & n for no)" << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 1) {
		move(a, c);
	}
	else {
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}

void move(char a, char c)
{
	cout << a << "-->" << c << endl;
}