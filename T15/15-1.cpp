#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

class Complex {
public:
	Complex(float i, float j) :real(i), imag(j) {}
	friend ostream& operator << (ostream& os, Complex& obj) {
		os << obj.real;
		if (obj.imag > 0) os << '+';
		if (obj.imag != 0) os << obj.imag << 'i';
		return os;
	}
	friend istream& operator >> (istream& is, Complex& obj) {
		cout << "Input the real, imag of the Complex:";
		is >> obj.real >> obj.imag;
		return is;
	}
private:
	float real, imag;
};

class Student {
public:
	char name[10];
	int num;
	int age;
	char address[15];
	friend ostream& operator << (ostream& os, Student& S) {
		os << S.name << " " << S.num << " " << S.age << " " << S.address << "\n";
		return os;
	}
	friend istream& operator >> (istream& is, Student& S) {
		is >> S.name >> S.num >> S.age >> S.address;
		return is;
	}
};

int main()
{
	cout << "书上部分例题测试" << endl;

	cout << setiosflags(ios::right)
		<< setw(5) << 1
		<< setw(5) << 2
		<< setw(5) << 3 << endl;
	cout << resetiosflags(ios::right)
		<< setiosflags(ios::left)
		<< setw(5) << 1
		<< setw(5) << 2
		<< setw(5) << 3 << endl;

	Complex C(3, 4);
	cout << C << endl;
	cin >> C;
	cout << C << endl;

	ofstream ofile;
	ifstream ifile;
	ofile.open("D:\\test.txt");
	if (ifile.fail()) { cout << "Can not open this file." << endl; }
	Student S;
	for (int i = 0; i < 3; ++i) {
		cout << "请输入第" << i+1 << "个学生的姓名、学号、年龄、住址" << endl;
		cin >> S;
		ofile << S;
	}
	ofile.close();
	cout << "读出文件内容" << endl;
	ifile.open("D:\\test.txt");
	if (ifile.fail()) { cout << "Can not open this file." << endl; }
	ifile >> S;
	while (!ifile.eof()) {
		cout << S;
		ifile >> S;
	}
	ifile.close();
	return 0;
}