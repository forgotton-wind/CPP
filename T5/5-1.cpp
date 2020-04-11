/*
��1�������ܼ��
���ݾ��������ѧ֪ʶ�����ʵ�־�������ˡ�ת�ú���ת��
��2���������˵��
1.ʵ��d1��d2��������ˡ�ת�ú���ת������d1��d2Ϊ�û����������������
2.�������ˡ�ת�ú���ת����ѧԭ����Լ򵥣���Ҫ�ǽ������ı�ʾ�����Բ���������������ַ�ʽ��
�Ȳ�����������ʾ�����ٲ�����������ʾ���󣬷ֱ�ʵ���������ݽṹ�¾�������ˡ�ת�ú���ת���䣬
���Ƚ��������ݽṹ�ĳ���ʵ�����׳̶ȣ�
3.���һ������Matrix���࣬���԰��������ά�ȱ���d1��d2����������뺯��Matrix_Input()��
�������ʾ����Matrix_Show()����������˺���Matrix_Multiply()�������ת�ú���Matrix_Transpose()��
�������ת����Matrix_Rotate()�ȳ�Ա���������Ӧ�Ĺ��캯����
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
	cout << "��������������ά��" << endl;
	cin >> d1;
	cin >> d2;
	a = new int* [d1];
	for (int i = 0; i < d1; i++) {
		a[i] = new int[d2];
	}
	cout << "���������Ԫ��" << endl;
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
	cout << "��ִ�������������ͷ��ڴ�" << endl;
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
	cout << "�����ά����" << d1 << '*' << d2 << endl;
}

void Matrix::matrixMultiply()
{
	int l;
	cout << "�����������ϵ�ϵ��" << endl;
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
	cout << "ת�ú�ľ���" << endl;
	for (int i = 0; i < d2; ++i) {
		for (int j = 0; j < d1; ++j) {
			cout << setw(5) << a[j][i] << ' ';
		}
		cout << endl;
	}
}

void Matrix::matrixRotation()
{
	cout << "������Ҫ˳ʱ����ת�ĽǶ�(90 or 180 or 270)��" << endl;
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
	cout << "�Ƿ�����������? ��-y,��-n" << endl;
	cin >> c;
	if (c == 'y') M.matrixMultiply();
	cout << "�Ƿ�������ת��? ��-y,��-n" << endl;
	cin >> c;
	if (c == 'y') M.matrixTranspose();
	cout << "�Ƿ���������ת? ��-y,��-n" << endl;
	cin >> c;
	if (c == 'y') M.matrixRotation();
	return 0;
}