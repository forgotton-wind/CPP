#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a = 9999;
	int b1 = 999;
	unsigned int b2 = 999;
	int c = 99;
	float d = 9.999;
	cout << "域宽为14，以数据符号左对齐、数据本身右对齐方式打印输出9999" << endl;
	cout << setw(14) << setiosflags(ios::showpos) << setiosflags(ios::internal) << a << endl;
	cout << "域宽为12，以有符号数和无符号数两种方式打印输出999" << endl;
	cout << setw(12) << resetiosflags(ios::internal) << b1 << resetiosflags(ios::showpos) << setw(12) << b2 << endl;
	cout << "域宽为10，以0x开头的十六进制格式打印输出99" << endl;
	cout << setw(10) << hex << showbase << c << endl;
	cout << "域宽为8，用前导符号$格式打印9.999" << endl;
	cout << setw(8) << setfill('$') << d << endl;
	return 0;
}