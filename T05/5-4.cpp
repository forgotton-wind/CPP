/*
（1）程序功能简介
实现一个中国好声音歌手报名的程序。
（2）程序设计说明
1 定义一个中国好声音歌手（Singer）类。其中，包括歌手的名字（name）、性别（gender）、年龄（age）、
  演唱曲目（song）等数据成员，提供Enroll()、Display()、Modify()等成员函数实现报名、显示、修改等功能；
2 提供合适的构造函数实现对象的创建，并利用对象数组实现多个歌手信息的登记；
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
	cout << "提示信息: 调用Singer构造函数" << endl;
}

Singer::~Singer()
{
	cout << "提示信息: 调用Singer析构函数" << endl;
}

void Singer::enroll()
{
	cout << "请输入歌手的信息(姓名、性别、年龄、演唱曲目): ";
	cin >> name >> gender >> age >> song;
}

void Singer::display()
{
	cout << name << " " << gender << " " << age << " " << song << endl;
}

void Singer::modify()
{
	int cho;
	cout << "1.姓名  2.性别  3.年龄  4.演唱曲目" << endl;
	cout << "请输入需要修改的选项: ";
	cin >> cho;
	switch (cho) {
	case 1:
		cout << "请输入新的姓名" << endl;
		cin >> name;
		break;
	case 2:
		cout << "请输入新的性别" << endl;
		cin >> gender;
		break;
	case 3:
		cout << "请输入新的年龄" << endl;
		cin >> age;
		break;
	case 4:
		cout << "请输入新的演唱曲目" << endl;
		cin >> song;
		break;
	default:
		cout << "输入不匹配" << endl;
	}
}

int main()
{
	int num;
	do {
		cout << "请输入这次报名歌手的数量(<=3): ";
		cin >> num;
		if (num >= NUM) cout << "超出最大人数限制" << endl;
	} while (num >= NUM);
	Singer A[NUM];
	cout << "********************************************" << endl;
	for (int i = 0; i < num; ++i) {
		A[i].enroll();
	}
	cout << "报名歌手信息如下所示: " << endl;
	for (int i = 0; i < num; ++i) {
		A[i].display();
	}
	cout << "是否需要修改歌手信息?(y/n): ";
	char c;
	int seq;
	cin >> c;
	while (c == 'y') {
		cout << "请输入需要修改的歌手信息序号" << endl;
		cin >> seq;
		A[seq - 1].modify();
		cout << "修改后歌手信息如下所示:" << endl;
		for (int i = 0; i < num; ++i) {
			A[i].display();
		}
		cout << "是否继续修改?(y/n)";
		cin >> c;
	}
	return 0;
}