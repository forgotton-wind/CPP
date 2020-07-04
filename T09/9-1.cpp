#include <iostream>
#include <string>

using namespace std;

class Grandfather {
public:
	string name;
	void showName() { cout << "The name of the grandfather is: " << name << endl; }
	Grandfather(string tname, int tage, string tcard_ID) :name(tname), age(tage), card_ID(tcard_ID) {}
	void showGrandfatherCardID() { showCardID(); }
protected:
	int age;
	void showAge() { cout << "The age of the grandfather is: " << age << endl; }
private:
	string card_ID;
	void showCardID() { cout << "The CardID of the grandfather is: " << card_ID << endl; }
};

class Father :public Grandfather {
public:
	string name;
	void showName() { cout << "The name of the father is: " << name << endl; }
	Father(string tn, int ta, string tc, string fn, int fa, string fc)
		:name(tn), age(ta), card_ID(tc), Grandfather(fn, fa, fc) {}
	void showFatherCardID() { showCardID(); }
protected:
	int age;
	void showAge() { cout << "The age of the father is: " << age << endl; }
private:
	string card_ID;
	void showCardID() { cout << "The CardID of the father is: " << card_ID << endl; }
};

class Son :public Father {
public:
	string name;
	void showName() { cout << "The name of the son is: " << name << endl; }
	Son(string tn, int ta, string tc, string fn, int fa, string fc, string ffn, int ffa, string ffc)
		:name(tn), age(ta), card_ID(tc), Father(fn, fa, fc, ffn, ffa, ffc) {}
	void showSonCardID() { showCardID(); }
protected:
	int age;
	void showAge() { cout << "The age of the son is: " << age << endl; }
private:
	string card_ID;
	void showCardID() { cout << "The CardID of the son is: " << card_ID << endl; }
};

int main()
{
	//以下代码为验证同名覆盖机制和局部优先原则；
	Grandfather g("Grandfather", 70, "123");
	g.showName();
	//g.showAge();
	//g.showCardID();
	Father f("Father", 40, "456", "Grandfather", 70, "123");
	f.showName();
	//f.showAge();
	//f.showCardID();
	Son s("Child", 10, "789", "Father", 40, "456", "Grandfather", 70, "123");
	s.showName();
	//s.showAge();
	//s.showCardID();

	//以下代码为验证支配规则（即作用域规则）；
	f.Grandfather::showName();
	s.Grandfather::showName();
	s.Father::showName();

	//以下代码为验证最近优先原则（需要注释掉Son类中的showName()成员函数）；
	s.showName();

	return 0;
}