#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
	char t;
	int num = 0;
	//���캯��ֱ�Ӵ��ļ�
	ifstream myf("C:\\Users\\18474\\Desktop\\file.txt");
	if (myf.fail()) cout << "file do not exists!" << endl;
	myf >> t;
	while (!myf.eof()) {
		if (t == 'a') num++;
		myf >> t;
	}
	cout << "���캯��ֱ�Ӵ��ļ�,�ַ�a�ĸ���Ϊ: " << num << endl;
	myf.close();
	//��open��ʽ���ļ�
	num = 0;
	ifstream myf2;
	myf2.open("C:\\Users\\18474\\Desktop\\file.txt");
	if (myf2.fail()) cout << "file do not exists!" << endl;
	myf2 >> t;
	while (!myf2.eof()) {
		if (t == 'a') num++;
		myf2 >> t;
	}
	cout << "��open��ʽ���ļ�,�ַ�a�ĸ���Ϊ: " << num << endl;
	myf2.close();
	return 0;
}
