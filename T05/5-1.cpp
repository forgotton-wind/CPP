/*
（1）程序功能简介
根据矩阵处理的数学知识，编程实现矩阵的数乘、转置和旋转。
（2）程序设计说明
1.实现d1×d2矩阵的数乘、转置和旋转，其中d1、d2为用户输入的任意整数；
2.矩阵数乘、转置和旋转的数学原理相对简单，主要是解决矩阵的表示，可以采用数组和链表两种方式：
先采用数组来表示矩阵，再采用链表来表示矩阵，分别实现两种数据结构下矩阵的数乘、转置和旋转反射，
并比较两种数据结构的程序实现难易程度；
3.设计一个矩阵（Matrix）类，可以包括矩阵的维度变量d1和d2、矩阵的输入函数Matrix_Input()、
矩阵的显示函数Matrix_Show()、矩阵的数乘函数Matrix_Multiply()、矩阵的转置函数Matrix_Transpose()、
矩阵的旋转函数Matrix_Rotate()等成员，定义好相应的构造函数；
*/
#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {
public:
	Matrix();
	void getDimension();
	void matrixShow();
	void matrixMultiply();
	void matrixTranspose();
	void matrixRotation();
	~Matrix();
private:
	int d1;
	int d2;
	int** a;
};

Matrix::Matrix()
{
	cout << "请输入矩阵的两个维度" << endl;
	cin >> d1;
	cin >> d2;
	a = new int* [d1];
	for (int i = 0; i < d1; i++) {
		a[i] = new int[d2];
	}
	cout << "请输入矩阵元素" << endl;
	for (int i = 0; i < d1; ++i) {
		for (int j = 0; j < d2; ++j) {
			cin >> a[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < d1; i++)
	{
		delete[] a[i];
		a[i] = NULL;
	}
	delete[] a;
	a = NULL;
	cout << "已执行析构函数，释放内存" << endl;
}

void Matrix::matrixShow()
{
	for (int i = 0; i < d1; ++i) {
		for (int j = 0; j < d2; ++j) {
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
}

void Matrix::getDimension()
{
	cout << "矩阵的维度是" << d1 << '*' << d2 << endl;
}

void Matrix::matrixMultiply()
{
	int l;
	cout << "请输入矩阵乘上的系数" << endl;
	cin >> l;
	for (int i = 0; i < d1; ++i) {
		for (int j = 0; j < d2; ++j) {
			cout << setw(5) << l * a[i][j] << ' ';
		}
		cout << endl;
	}
}

void Matrix::matrixTranspose()
{
	cout << "转置后的矩阵：" << endl;
	for (int i = 0; i < d2; ++i) {
		for (int j = 0; j < d1; ++j) {
			cout << setw(5) << a[j][i] << ' ';
		}
		cout << endl;
	}
}

void Matrix::matrixRotation()
{
	cout << "请输入要顺时针旋转的角度(90 or 180 or 270)：" << endl;
	int arc;
	cin >> arc;
	if (arc == 90) {
		for (int i = 0; i < d2; ++i) {
			for (int j = d1 - 1; j >= 0; --j) {
				cout << setw(5) << a[j][i] << ' ';
			}
			cout << endl;
		}
	}
	else if (arc == 180) {
		for (int i = d1 - 1; i >= 0; --i) {
			for (int j = d2 - 1; j >= 0; --j) {
				cout << setw(5) << a[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else if (arc == 270) {
		for (int i = d2 - 1; i >= 0; --i) {
			for (int j = 0; j < d1; ++j) {
				cout << setw(5) << a[j][i] << ' ';
			}
			cout << endl;
		}
	}
}

int main()
{
	Matrix M;
	M.getDimension();
	M.matrixShow();
	char c = 'y';
	cout << "是否做矩阵数乘? 是-y,否-n" << endl;
	cin >> c;
	if (c == 'y') M.matrixMultiply();
	cout << "是否做矩阵转置? 是-y,否-n" << endl;
	cin >> c;
	if (c == 'y') M.matrixTranspose();
	cout << "是否做矩阵旋转? 是-y,否-n" << endl;
	cin >> c;
	if (c == 'y') M.matrixRotation();
	return 0;
}