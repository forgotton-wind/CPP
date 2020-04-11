/*
��1�������ܼ��
ʵ��һ�����м��������ܵĳ���
��2���������˵��
�û����ݳ�����ʾ�������֣�ѡ��Ҫ���е����㣬���Խ��мӡ������ˡ�����ƽ������ģ���󷽸������㣻
��Լӡ������ˡ�����ƽ������ģ���󷽸�������ÿ�ֲ������һ����Ա����ʵ����Ӧ���ܣ�
*/

#include <iostream>
#include <cmath>

using namespace std;

class calculator {
public:
	double add(double a, double b);
	double sub(double a, double b);
	double mul(double a, double b);
	double div(double a, double b);
	double square(double a);
	double modulus(double a);
	double squareRoot(double a);
};

double calculator::add(double a, double b)
{
	double res = a + b;
	cout << a << "+" << b << "=" << res << endl;
	return res;
}

double calculator::sub(double a, double b)
{
	double res = a - b;
	cout << a << "-" << b << "=" << res << endl;
	return res;
}

double calculator::mul(double a, double b)
{
	double res = a * b;
	cout << a << "*" << b << "=" << res << endl;
	return res;

}

double calculator::div(double a, double b)
{
	double res = a / b;
	cout << a << "/" << b << "=" << res << endl;
	return res;
}

double calculator::square(double a)
{
	double res = a * a;
	cout << a << "*" << a << "=" << res << endl;
	return res;
}

double calculator::modulus(double a)
{
	double res = fabs(a);
	cout << '|' << a << '|' << "=" << res << endl;
	return res;
}

double calculator::squareRoot(double a)
{
	double res = sqrt(a);
	cout << a << '^' << "(1/2)" << '=' << res << endl;
 	return res;
}


int main()
{
	calculator A;
	cout << "���׼�����" << endl;
	cout << "�������:" << endl;
	cout << "�ӷ�+ " << "����- " << "�˷�* " << "����/ " << "ƽ��^ " << "ģ| " << "����# " << endl;
	char c = 'y';
	double a, b;
	char op;
restart:
	cout << "�����������" << endl;
	cin >> a;
	while (c == 'y') {
		cout << "�����������" << endl;
		cin >> op;
		switch (op)
		{
		case '+':
			cout << "�����������" << endl;
			cin >> b;
			cout << "������Ϊ" << endl;
			a = A.add(a, b);
			break;
		case '-':
			cout << "�����������" << endl;
			cin >> b;
			cout << "������Ϊ" << endl;
			a = A.sub(a, b);
			break;
		case '*':
			cout << "�����������" << endl;
			cin >> b;
			cout << "������Ϊ" << endl;
			a = A.mul(a, b);
			break;
		case '/':
			cout << "�����������" << endl;
			cin >> b;
			if (b == 0) {
				cout << "��������Ϊ0" << endl;
				goto restart;
			}
			else {
				cout << "������Ϊ" << endl;
				a = A.div(a, b);
			}
			break;
		case '^':
			cout << "������Ϊ" << endl;
			a = A.square(a);
			break;
		case '|':
			cout << "������Ϊ" << endl;
			a = A.modulus(a);
			break;
		case '#':
			if (a >= 0) {
				cout << "������Ϊ" << endl;
				a = A.squareRoot(a);
			}
			else {
				cout << "�������ܿ�����" << endl;
				goto restart;
			}
			break;
		default:
			cout << "ERROR!!!";
			break;
		}
		cout << "�Ƿ��������-y,��-n" << endl;
		cin >> c;
	}
	return 0;
}