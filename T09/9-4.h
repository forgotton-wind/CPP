#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//总部类
class headquarters {
	int lifeValue, redOrBlue, count;		//redOrBlue为总部值，红色总部值为0，蓝色总部值为1；count生产的战士数量
	int* warriorCounts, * warriorValues;	//warriorCounts记录每种战士数量的数组，warriorValues记录每种战士生命值的数组
	string headquarterName, * warriorNames;	//headquarterName为总部的名字，*warriorNames为记录每种战士名字的数组
public:
	headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], const string theWarriorNames[], const int order[], const string theHeadquarterNames[]);
	~headquarters();
	int getCount() { return count; }			//获取出生数，用于战士的id计算
	int getLifeValue() { return lifeValue; }	//获取生命值，用于在main程序中与各战士的最小生命值比较，以及与战士生命值的比较
	int getWarriorValue(int position) { return warriorValues[position]; }	//获取将要出生的战士的生命值
	string getWarriorName(int position) { return warriorNames[position]; }	//获取将要出生的战士的名字
	void product(int time, int position);		//生产战士
};
headquarters::headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], const string theWarriorNames[], const int order[], const string theHeadquarterNames[]) {
	count = 0;  lifeValue = theLifeValue;  redOrBlue = theRedOrBlue;
	headquarterName = theHeadquarterNames[redOrBlue];  //从总部名字的数组取得该总部的名字
	warriorCounts = new int[5]();
	warriorValues = new int[5];
	warriorNames = new string[5];
	for (int i = 0; i < 5; ++i) {
		warriorNames[i] = theWarriorNames[order[i]];   //由给定的顺序和原始战士名字的数组，得到该总部战士名字的数组
		warriorValues[i] = theWarriorValue[order[i]];  //由给定的顺序和原始战士名字的数组，得到该总部战士生命值的数组
	}
}
headquarters::~headquarters() {
	if (warriorCounts) delete[]warriorCounts;
	if (warriorValues) delete[]warriorValues;
	if (warriorNames) delete[]warriorNames;
}
void headquarters::product(int time, int position) {
	count++;
	warriorCounts[position]++;							//该种战士的总数加一
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "时间: "<< setfill('0') << setw(3) << time << " 总部: " << headquarterName << " ";
	cout << "生成: " << warriorNames[position] << " 编号:" << count << " 生命值: " << warriorValues[position];
	cout << " 统计: " << warriorCounts[position] << " " << warriorNames[position] << " in " << headquarterName << " headquarter" << endl;
	lifeValue -= warriorValues[position];
}

class warrior {
	int id, lifeValue;
	static string weaponNames[3];
public:
	warrior() :id(0), lifeValue(0) {}
	warrior(int theId, int theLifeValue) :id(theId), lifeValue(theLifeValue) {}
	//~warrior() { if (weaponNames) delete[]weaponNames; }
	int getId() { return id; }
	string* getWeaponNames() { return weaponNames; }
};
string warrior::weaponNames[3] = { "sword","bomb","arrow" };

class dragon :public warrior {
	float morale;
public:
	dragon(int theId, int theLifeValue, int headquarterLifeValue) :warrior(theId, theLifeValue)
	{
		morale = (float)(headquarterLifeValue) / theLifeValue;
	}
	~dragon() {};
	float getMorale() { return morale; }
	string getWeaponName() { int index = this->getId() % 3; return this->getWeaponNames()[index]; }
	void print()
	{
		cout << "It has a " << getWeaponName() << ", and it's morale is " << setprecision(2) << fixed << getMorale() << endl;
	}
};

class ninja :public warrior {
public:
	ninja(int theId, int theLifeValue) :warrior(theId, theLifeValue) {}
	~ninja() {}
	string getFirstWeaponName() {
		int index = this->getId() % 3;
		return this->getWeaponNames()[index];
	}
	string getSecondWeaponName() {
		int index = (this->getId() + 1) % 3;
		return this->getWeaponNames()[index];
	}
	void print() { cout << "It has a " << this->getFirstWeaponName() << " and a " << this->getSecondWeaponName() << endl; }
};

class iceman :public warrior {
public:
	iceman(int theId, int theLifeValue) :warrior(theId, theLifeValue) {}
	~iceman() {};
	string getWeaponName() {
		int index = this->getId() % 3;
		return this->getWeaponNames()[index];
	}
	void print() { cout << "It has a " << this->getWeaponName() << endl; }
};

class lion :public warrior {
	int loyalty;
public:
	lion(int theId, int theLifeValue, int headquarterLifeValue) :warrior(theId, theLifeValue)
	{
		loyalty = headquarterLifeValue;
	}
	~lion() {}
	int getLoyalty() { return loyalty; }
	void print() { cout << "It's loyalty is " << this->getLoyalty() << endl; }
};

class wolf :public warrior {
public:
	wolf(int theId, int theLifeValue) :warrior(theId, theLifeValue) {}
	~wolf() {}
};