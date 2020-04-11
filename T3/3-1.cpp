#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "3-1.h"
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
	int l;
	cout << "�����������ϵ�ϵ��" << endl;
	cin >> l;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << setw(5) << l * array[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < row; ++i) {
		free(array[i]);
	}
	free(array);
}

//����ʵ�־���
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
	cout << "ԭʼ����Ϊ��" << endl;
	Node* h = L.head;
	for (int i = 0; i < row * column; ++i) {
		cout << setw(5) << h->next->data << ' ';
		h = h->next;
		if ((i+1) % row == 0) cout << endl;
	}
	int l;
	cout << "�����������ϵ�ϵ��" << endl;
	cin >> l;
	h = L.head;
	for (int i = 0; i < row * column; ++i) {
		cout << setw(5) << l*(h->next->data) << ' ';
		h = h->next;
		if ((i + 1) % row == 0) cout << endl;
	}
	//����free�ˣ���Ӱ�죬��Ȼ���˸��á�
}
