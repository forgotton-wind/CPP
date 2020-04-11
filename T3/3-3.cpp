#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "3-3.h"
using namespace std;

int main()
{
	int row, column, key;
	cout << "请输入矩阵维度" << endl;
	cout << "矩阵行数：" << endl;
	cin >> row;
	cout << "矩阵列数：" << endl;
	cin >> column;
	cout << "查看 采用数组实现or链表实现？(数组实现键入1，链表实现键入2)" << endl;
	cin >> key;
	if (key == 1) func1(row, column);
	else func2(row, column);
	return 0;
}

//数组表示矩阵
void func1(int row, int column)
{
	int** array = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; ++i) {
		array[i] = (int*)malloc(sizeof(int) * column);
	}
	cout << "请输入矩阵元素" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cin >> array[i][j];
		}
	}
	cout << "原始矩阵为：" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << setw(5) << array[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "请输入要顺时针旋转的角度(90 or 180 or 270)：" << endl;
	int arc;
	cin >> arc;
	if (arc == 90) {
		for (int i = 0; i < column ; ++i) {
			for (int j = row-1; j >= 0; --j) {
				cout << setw(5) << array[j][i] << ' ';
			}
			cout << endl;
		}
	}
	else if (arc == 180) {
		for (int i = row - 1; i >=0; --i) {
			for (int j = column - 1; j >= 0; --j) {
				cout << setw(5) << array[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else if (arc == 270) {
		for (int i = column- 1; i >= 0; --i) {
			for (int j = 0; j < row; ++j) {
				cout << setw(5) << array[j][i] << ' ';
			}
			cout << endl;
		}
	}
	for (int i = 0; i < row; ++i) {
		free(array[i]);
	}
	free(array);
}

//链表表示矩阵
void func2(int row, int column)
{
	List L;
	int num;
	L.head = L.tail = NULL;
	L.head = (Node*)malloc(sizeof(Node));
	L.tail = (Node*)malloc(sizeof(Node));
	L.head->next = L.tail->next = NULL;
	cout << "请输入矩阵元素" << endl;
	for (int i = 0; i < row * column; i++) {
		cin >> num;
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = num;
		p->next = NULL;
		if (L.tail->next) {
			L.tail->next->next = p;
			L.tail->next = p;
		}
		else {
			L.head->next = p;
			L.tail->next = p;
		}
	}
	L.tail->next->next = L.head->next;		//构造循环链表
	cout << "原始矩阵为：" << endl;
	Node* h = L.head;
	for (int i = 0; i < row * column; ++i) {
		cout << setw(5) << h->next->data << ' ';
		h = h->next;
		if ((i + 1) % column == 0) cout << endl;
	}
	cout << "请输入要顺时针旋转的角度(90 or 180 or 270)：" << endl;
	int arc;
	cin >> arc;
	int c;
	if (arc == 90) {
		for (int k = 0; k < column; k++) {
			h = L.head;
			for (c = k; c > 0; --c) h = h->next;
			for (int j = 0; j < row; ++j) {
				for (int i = 0; i < column * (row - 1); ++i) h = h->next;
				cout << setw(5) << h->next->data << ' ';
			}
			cout << endl;
		}
	}
	h = L.head;
	if (arc == 180) {
		for (int i = 0; i < row * column; ++i) {
			for (int j = 0; j < row * column - 1; ++j) h = h->next;
			cout << setw(5) << h->next->data << ' ';
			if ((i + 1) % column == 0) cout << endl;
		}
	}
	if (arc == 270) {
		for (int k = 0; k < column; k++) {
			h = L.head;
			for (c = column - k - 1; c > 0; --c) h = h->next;
			for (int j = 0; j < row; ++j) {
				cout << setw(5) << h->next->data << ' ';
				for (int i = 0; i < column; ++i) h = h->next;
			}
			cout << endl;
		}
	}
	//不做free了，无影响，当然做了更好。
}