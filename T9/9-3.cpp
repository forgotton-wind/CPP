#include <iostream>
#include <string>

using namespace std;

class Automobile {
public:
	Automobile(string tplate_NO) :plate_NO(tplate_NO) {}
	void enter(class Park&);
	void leave(class Park&, int);
protected:
	string plate_NO;
};

class Truck :public Automobile {
public:
	Truck(string tplate_NO, double tload) :Automobile(tplate_NO), load(tload) {}
	void leave(class Park& p) { Automobile::leave(p, 3); }
private:
	double load;
};

class Bus :public Automobile {
public:
	Bus(string tplant_NO, int tcapacity) :Automobile(tplant_NO), capacity(tcapacity) {}
	void leave(class Park& p) { Automobile::leave(p, 2); }
private:
	int capacity;
};

class Car :public Automobile {
public:
	Car(string tplant_NO, string tbrand) :Automobile(tplant_NO), brand(tbrand) {}
	void leave(class Park& p) { Automobile::leave(p, 1); }
private:
	string brand;
};

class Park {
public:
	Park(int n) :N(n) { a = new string[N](); }
	void showParkInfo();
	friend void Automobile::enter(class Park&);
	friend void Automobile::leave(class Park&, int);
private:
	int N;
	string* a;
	int income = 0;
	int num = 0;
};

void Automobile::enter(class Park& p)
{
	int i;
	for (i = 0; i < p.N; ++i) {
		if (p.a[i] == string()) {
			p.a[i] = plate_NO;
			cout << plate_NO << "进入停车场" << endl;
			p.num++;
			break;
		}
	}
	if (i == p.N) {
		cout << "无法为" << plate_NO <<"分配停车位，已经没有可用的停车位!" << endl;
	}
}

void Automobile::leave(class Park& p, int n)
{
	int i;
	for (i = 0; i < p.N; ++i) {
		if (p.a[i] == plate_NO) {
			p.a[i] = string();
			cout << plate_NO << "离开停车场，缴费"<< n << "元!" << endl;
			p.income += n;
			p.num--;
			break;
		}
	}
	if (i == p.N) {
		cout << plate_NO << "离开停车场" << endl;
	}
}

void Park::showParkInfo()
{
	cout << endl << "****************停车场当前信息如下*****************" << endl;
	cout << "停有车辆: " << num << "  ";
	for (int i = 0; i < N; ++i) {
		if (a[i] != string()) {
			cout << a[i] << "  ";
		}
	}
	cout << endl << "共计收入: " << income << endl;
	cout << "***************************************************" << endl;
}

int main()
{
	int n;
	cout << "请输入停车场最大车位数: ";
	cin >> n;
	Park p(n);
	Truck truck("苏A-01234", 20);
	truck.enter(p);
	Car car1("苏A-56789", "Audi A8");
	car1.enter(p);
	car1.leave(p);
	Bus bus("苏A-43210", 50);
	bus.enter(p);
	p.showParkInfo();
	Car car2("苏A-98765", "Benz S400");
	car2.enter(p);
	bus.leave(p);
	truck.leave(p);
	p.showParkInfo();
	return 0;
}
