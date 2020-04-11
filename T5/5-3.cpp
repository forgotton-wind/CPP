/*
��1�������ܼ��
��Ƴ��򴴽�һ�������࣬�ܹ�ʵ������ĸ�����Ҫ������
��2���������˵��
�� ���һ�������࣬������Ϣ���£�
	����Ļ������ԣ����ȡ�Ԫ�أ�
	����Ļ�����������ʾ�����򡢲��롢ɾ�������ҵȡ�
�� ����һ�����飨����������Ϊ������Array���ࡣ������Ա���£�
	const int MaxSize=10;
	class Array{
		int length, data[MaxSize];
	public:
		Array();//�൱�ڳ�ʼ��������һ�������飬����Ϊ0
		Array(int olda[],int n);//�ø�������Ϊn������olda��ʼ�����ݳ�Ա
		void Display();//��ʾ��������Ԫ��
		void Insert(int x);//��������Ԫ��x���뵽�����к��Ա�������������ԣ���Ҫ�жϲ�����Ԫ�ػ᲻�ᷢ���洢�ռ���������������������ʾ�������ʧ�ܣ���������У�����λ��ȷ���󣬴Ӳ���λ�������һ��Ԫ��ȫ��������һλ�����²���Ԫ�ؿճ�����λ��
		void Delete(int x);//��������ɾ��ָ��Ԫ��x�������Ԫ��ȫ��Ҫ��ǰ��һλ����ɾ��ǰ��Ҫ�ж������Ƿ�Ϊ�գ���Ϊ�ձ���ɾ������ʧ��
		int Search(int x);//�������в���ָ��Ԫ��x�������ҳɹ�����Ԫ����������λ�ã�����ʧ�ܷ����ض�ֵ-1
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
	cout << "���ù��캯����ʼ������" << endl;
	length = 0;
	for (int i = 0; i < 10; ++i) data[i] = 0;
}

Array::Array(int oldarray[], int n)
{
	cout << "���ù��캯����ʼ������" << endl;
	length = n;
	for (int i = 0; i < n; ++i) data[i] = oldarray[i];
}

void Array::display()
{
	cout << "��ʾ����Ԫ��" << endl;
	for (int i = 0; i < length; ++i) cout << data[i] << ' ';
	cout << endl;
}

void Array::insert(int x)
{
	if (length < Maxsize) {
		data[length] = x;
		length++;
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "����ʧ�ܣ��Ѵ��������ߣ������ٲ���" << endl;
	}
}

void Array::arrayDelete(int x)
{
	if (length == 0) cout << "ɾ��ʧ�ܣ�û��Ԫ�أ��޷�ɾ��" << endl;
	else {
		int i;
		for (i = 0; i < length; ++i) {
			if (data[i] == x) break;
		}
		if (i == length) cout << "ɾ��ʧ�ܣ��Ҳ��������" << endl;
		else {
			for (int j = i; j < length - 1; ++j) {
				data[j] = data[j + 1];
			}
			length--;
			cout << "ɾ���ɹ�" << endl;
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
		cout << "����ɹ�" << endl;
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
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "����ʧ�ܣ����������벻��ȷ" << endl;
	}
}

int welcome()
{
	cout << "****************************************************" << endl;
	cout << "** 1.��ʾ  2.����  3.����  4.ɾ��  5.����  6.�˳� **" << endl;
	cout << "****************************************************" << endl;
	cout << "��ѡ�������:  " << endl;
	int x;
	cin >> x;
	return x;
}

int main()
{
	int len, x;
	cout << "���������鳤��(������10): ";
	cin >> len;
	int *b = new int[len];
	cout << "����������Ԫ��: ";
	for (int i = 0; i < len; ++i) cin >> b[i];
	Array a(b, len);

	do {
		x = welcome();
		switch (x) {
		case 1:
			a.display();
			break;
		case 2:
			cout << "����������ģʽ�������� ���� 0������ 1: ";
			cin >> x;
			a.order(x);
			a.display();
			break;
		case 3:
			cout << "������Ҫ���������" << endl;
			cin >> x;
			a.insert(x);
			break;
		case 4:
			cout << "������Ҫɾ��������: " << endl;
			cin >> x;
			a.arrayDelete(x);
			break;
		case 5:
			cout << "������Ҫ���ҵ�����: " << endl;
			cin >> x;
			x = a.search(x);
			if (x != -1) cout << "���ҳɹ���������λ����: " << x << endl;
			else cout << "δ�ҵ�" << endl;
			break;
		case 6:
			break;
		default:
			cout << "���벻��ȷ" << endl;
		}
	} while (x != 6);
	return 0;
}