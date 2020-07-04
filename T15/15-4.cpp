#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
	char t;
	int num = 0;
	//构造函数直接打开文件
	ifstream myf("C:\\Users\\18474\\Desktop\\file.txt");
	if (myf.fail()) cout << "file do not exists!" << endl;
	myf >> t;
	while (!myf.eof()) {
		if (t == 'a') num++;
		myf >> t;
	}
	cout << "构造函数直接打开文件,字符a的个数为: " << num << endl;
	myf.close();
	//用open方式打开文件
	num = 0;
	ifstream myf2;
	myf2.open("C:\\Users\\18474\\Desktop\\file.txt");
	if (myf2.fail()) cout << "file do not exists!" << endl;
	myf2 >> t;
	while (!myf2.eof()) {
		if (t == 'a') num++;
		myf2 >> t;
	}
	cout << "用open方式打开文件,字符a的个数为: " << num << endl;
	myf2.close();
	return 0;
}
