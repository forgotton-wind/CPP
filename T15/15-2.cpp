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
	cout << "���Ϊ14�������ݷ�������롢���ݱ����Ҷ��뷽ʽ��ӡ���9999" << endl;
	cout << setw(14) << setiosflags(ios::showpos) << setiosflags(ios::internal) << a << endl;
	cout << "���Ϊ12�����з��������޷��������ַ�ʽ��ӡ���999" << endl;
	cout << setw(12) << resetiosflags(ios::internal) << b1 << resetiosflags(ios::showpos) << setw(12) << b2 << endl;
	cout << "���Ϊ10����0x��ͷ��ʮ�����Ƹ�ʽ��ӡ���99" << endl;
	cout << setw(10) << hex << showbase << c << endl;
	cout << "���Ϊ8����ǰ������$��ʽ��ӡ9.999" << endl;
	cout << setw(8) << setfill('$') << d << endl;
	return 0;
}