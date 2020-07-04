/*
��1�������ܼ��
ʵ��һ���й����������ֱ����ĳ���
��2���������˵��
1 ����һ���й����������֣�Singer���ࡣ���У��������ֵ����֣�name�����Ա�gender�������䣨age����
  �ݳ���Ŀ��song�������ݳ�Ա���ṩEnroll()��Display()��Modify()�ȳ�Ա����ʵ�ֱ�������ʾ���޸ĵȹ��ܣ�
2 �ṩ���ʵĹ��캯��ʵ�ֶ���Ĵ����������ö�������ʵ�ֶ��������Ϣ�ĵǼǣ�
*/
#include <iostream>
#define NUM 3

using namespace std;

class Singer {
public:
	Singer();
	void enroll();
	void display();
	void modify();
	~Singer();
private:
	char name[20];
	char gender[5];
	int age;
	char song[20];
};

Singer::Singer()
{
	cout << "��ʾ��Ϣ: ����Singer���캯��" << endl;
}

Singer::~Singer()
{
	cout << "��ʾ��Ϣ: ����Singer��������" << endl;
}

void Singer::enroll()
{
	cout << "��������ֵ���Ϣ(�������Ա����䡢�ݳ���Ŀ): ";
	cin >> name >> gender >> age >> song;
}

void Singer::display()
{
	cout << name << " " << gender << " " << age << " " << song << endl;
}

void Singer::modify()
{
	int cho;
	cout << "1.����  2.�Ա�  3.����  4.�ݳ���Ŀ" << endl;
	cout << "��������Ҫ�޸ĵ�ѡ��: ";
	cin >> cho;
	switch (cho) {
	case 1:
		cout << "�������µ�����" << endl;
		cin >> name;
		break;
	case 2:
		cout << "�������µ��Ա�" << endl;
		cin >> gender;
		break;
	case 3:
		cout << "�������µ�����" << endl;
		cin >> age;
		break;
	case 4:
		cout << "�������µ��ݳ���Ŀ" << endl;
		cin >> song;
		break;
	default:
		cout << "���벻ƥ��" << endl;
	}
}

int main()
{
	int num;
	do {
		cout << "��������α������ֵ�����(<=3): ";
		cin >> num;
		if (num >= NUM) cout << "���������������" << endl;
	} while (num >= NUM);
	Singer A[NUM];
	cout << "********************************************" << endl;
	for (int i = 0; i < num; ++i) {
		A[i].enroll();
	}
	cout << "����������Ϣ������ʾ: " << endl;
	for (int i = 0; i < num; ++i) {
		A[i].display();
	}
	cout << "�Ƿ���Ҫ�޸ĸ�����Ϣ?(y/n): ";
	char c;
	int seq;
	cin >> c;
	while (c == 'y') {
		cout << "��������Ҫ�޸ĵĸ�����Ϣ���" << endl;
		cin >> seq;
		A[seq - 1].modify();
		cout << "�޸ĺ������Ϣ������ʾ:" << endl;
		for (int i = 0; i < num; ++i) {
			A[i].display();
		}
		cout << "�Ƿ�����޸�?(y/n)";
		cin >> c;
	}
	return 0;
}