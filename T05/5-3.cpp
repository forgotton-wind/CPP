/*
（1）程序功能简介
设计程序创建一个数组类，能够实现数组的各种主要操作。
（2）程序设计说明
① 设计一个数组类，基本信息如下：
	数组的基本属性：长度、元素；
	数组的基本操作：显示、排序、插入、删除、查找等。
② 定义一个数组（以整型数组为例）（Array）类。基本成员如下：
	const int MaxSize=10;
	class Array{
		int length, data[MaxSize];
	public:
		Array();//相当于初始化操作，一个空数组，长度为0
		Array(int olda[],int n);//用给定长度为n的数组olda初始化数据成员
		void Display();//显示所有数组元素
		void Insert(int x);//将给定的元素x插入到数组中后，仍保持数组的有序性；需要判断插入新元素会不会发生存储空间的溢出情况，若发生溢出提示插入操作失败；插入过程中，插入位置确定后，从插入位置至最后一个元素全部往后移一位，给新插入元素空出插入位置
		void Delete(int x);//从数组中删除指定元素x，后面的元素全部要往前移一位；做删除前需要判断数组是否为空，若为空表，则删除操作失败
		int Search(int x);//从数组中查找指定元素x，若查找成功返回元素在数组中位置，查找失败返回特定值-1
	};
*/
#include <iostream>

using namespace std;

const int Maxsize = 10;
class Array {
public:
	Array();
	Array(int oldarray[], int n);
	void display();
	void insert(int x);
	void arrayDelete(int x);
	int search(int x);
	void order(int mode);
private:
	int length, data[Maxsize];
};

Array::Array()
{
	cout << "调用构造函数初始化数组" << endl;
	length = 0;
	for (int i = 0; i < 10; ++i) data[i] = 0;
}

Array::Array(int oldarray[], int n)
{
	cout << "调用构造函数初始化数组" << endl;
	length = n;
	for (int i = 0; i < n; ++i) data[i] = oldarray[i];
}

void Array::display()
{
	cout << "显示数组元素" << endl;
	for (int i = 0; i < length; ++i) cout << data[i] << ' ';
	cout << endl;
}

void Array::insert(int x)
{
	if (length < Maxsize) {
		data[length] = x;
		length++;
		cout << "插入成功" << endl;
	}
	else {
		cout << "插入失败，已达数组上线，不能再插入" << endl;
	}
}

void Array::arrayDelete(int x)
{
	if (length == 0) cout << "删除失败，没有元素，无法删除" << endl;
	else {
		int i;
		for (i = 0; i < length; ++i) {
			if (data[i] == x) break;
		}
		if (i == length) cout << "删除失败，找不到这个数" << endl;
		else {
			for (int j = i; j < length - 1; ++j) {
				data[j] = data[j + 1];
			}
			length--;
			cout << "删除成功" << endl;
		}
	}
}

int Array::search(int x)
{
	for (int i = 0; i < length; ++i) {
		if (data[i] == x) return i+1;
	}
	return -1;
}

void Array::order(int mode)
{
	int t;
	if (mode == 0) {
		for (int i = 0; i < length - 1; ++i) {
			for (int j = 0; j < length - i - 1; ++j) {
				if (data[j] > data[j + 1]) {
					t = data[j];
					data[j] = data[j + 1];
					data[j + 1] = t;
				}
			}
		}
		cout << "排序成功" << endl;
	}
	else if (mode == 1) {
		for (int i = 0; i < length - 1; ++i) {
			for (int j = 0; j < length - i - 1; ++j) {
				if (data[j] < data[j + 1]) {
					t = data[j];
					data[j] = data[j + 1];
					data[j + 1] = t;
				}
			}
		}
		cout << "排序成功" << endl;
	}
	else {
		cout << "排序失败，升序降序输入不正确" << endl;
	}
}

int welcome()
{
	cout << "****************************************************" << endl;
	cout << "** 1.显示  2.排序  3.插入  4.删除  5.查找  6.退出 **" << endl;
	cout << "****************************************************" << endl;
	cout << "请选择操作项:  " << endl;
	int x;
	cin >> x;
	return x;
}

int main()
{
	int len, x;
	cout << "请输入数组长度(不大于10): ";
	cin >> len;
	int *b = new int[len];
	cout << "请输入数组元素: ";
	for (int i = 0; i < len; ++i) cin >> b[i];
	Array a(b, len);

	do {
		x = welcome();
		switch (x) {
		case 1:
			a.display();
			break;
		case 2:
			cout << "请输入排序模式———— 升序 0，降序 1: ";
			cin >> x;
			a.order(x);
			a.display();
			break;
		case 3:
			cout << "请输入要插入的数字" << endl;
			cin >> x;
			a.insert(x);
			break;
		case 4:
			cout << "请输入要删除的数字: " << endl;
			cin >> x;
			a.arrayDelete(x);
			break;
		case 5:
			cout << "请输入要查找的数字: " << endl;
			cin >> x;
			x = a.search(x);
			if (x != -1) cout << "查找成功，此数字位置是: " << x << endl;
			else cout << "未找到" << endl;
			break;
		case 6:
			break;
		default:
			cout << "输入不正确" << endl;
		}
	} while (x != 6);
	return 0;
}