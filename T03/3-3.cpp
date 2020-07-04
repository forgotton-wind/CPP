#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "3-3.h"
using namespace std;

int main()
{
	int row, column, key;
	cout << "���������ά��" << endl;
	cout << "����������" << endl;
	cin >> row;
	cout << "����������" << endl;
	cin >> column;
	cout << "�鿴 ��������ʵ��or����ʵ�֣�(����ʵ�ּ���1������ʵ�ּ���2)" << endl;
	cin >> key;
	if (key == 1) func1(row, column);
	else func2(row, column);
	return 0;
}

//�����ʾ����
void func1(int row, int column)
{
	int** array = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; ++i) {
		array[i] = (int*)malloc(sizeof(int) * column);
	}
	cout << "���������Ԫ��" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cin >> array[i][j];
		}
	}
	cout << "ԭʼ����Ϊ��" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << setw(5) << array[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "������Ҫ˳ʱ����ת�ĽǶ�(90 or 180 or 270)��" << endl;
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

//�����ʾ����
void func2(int row, int column)
{
	List L;
	int num;
	L.head = L.tail = NULL;
	L.head = (Node*)malloc(sizeof(Node));
	L.tail = (Node*)malloc(sizeof(Node));
	L.head->next = L.tail->next = NULL;
	cout << "���������Ԫ��" << endl;
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
	L.tail->next->next = L.head->next;		//����ѭ������
	cout << "ԭʼ����Ϊ��" << endl;
	Node* h = L.head;
	for (int i = 0; i < row * column; ++i) {
		cout << setw(5) << h->next->data << ' ';
		h = h->next;
		if ((i + 1) % column == 0) cout << endl;
	}
	cout << "������Ҫ˳ʱ����ת�ĽǶ�(90 or 180 or 270)��" << endl;
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
	//����free�ˣ���Ӱ�죬��Ȼ���˸��á�
}