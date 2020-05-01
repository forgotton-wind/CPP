#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//�ܲ���
class headquarters {
	int lifeValue, redOrBlue, count;		//redOrBlueΪ�ܲ�ֵ����ɫ�ܲ�ֵΪ0����ɫ�ܲ�ֵΪ1��count������սʿ����
	int* warriorCounts, * warriorValues;	//warriorCounts��¼ÿ��սʿ���������飬warriorValues��¼ÿ��սʿ����ֵ������
	string headquarterName, * warriorNames;	//headquarterNameΪ�ܲ������֣�*warriorNamesΪ��¼ÿ��սʿ���ֵ�����
public:
	headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], const string theWarriorNames[], const int order[], const string theHeadquarterNames[]);
	~headquarters();
	int getCount() { return count; }			//��ȡ������������սʿ��id����
	int getLifeValue() { return lifeValue; }	//��ȡ����ֵ��������main���������սʿ����С����ֵ�Ƚϣ��Լ���սʿ����ֵ�ıȽ�
	int getWarriorValue(int position) { return warriorValues[position]; }	//��ȡ��Ҫ������սʿ������ֵ
	string getWarriorName(int position) { return warriorNames[position]; }	//��ȡ��Ҫ������սʿ������
	void product(int time, int position);		//����սʿ
};
headquarters::headquarters(const int theLifeValue, const int theRedOrBlue, const int theWarriorValue[], const string theWarriorNames[], const int order[], const string theHeadquarterNames[]) {
	count = 0;  lifeValue = theLifeValue;  redOrBlue = theRedOrBlue;
	headquarterName = theHeadquarterNames[redOrBlue];  //���ܲ����ֵ�����ȡ�ø��ܲ�������
	warriorCounts = new int[5]();
	warriorValues = new int[5];
	warriorNames = new string[5];
	for (int i = 0; i < 5; ++i) {
		warriorNames[i] = theWarriorNames[order[i]];   //�ɸ�����˳���ԭʼսʿ���ֵ����飬�õ����ܲ�սʿ���ֵ�����
		warriorValues[i] = theWarriorValue[order[i]];  //�ɸ�����˳���ԭʼսʿ���ֵ����飬�õ����ܲ�սʿ����ֵ������
	}
}
headquarters::~headquarters() {
	if (warriorCounts) delete[]warriorCounts;
	if (warriorValues) delete[]warriorValues;
	if (warriorNames) delete[]warriorNames;
}
void headquarters::product(int time, int position) {
	count++;
	warriorCounts[position]++;							//����սʿ��������һ
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "ʱ��: "<< setfill('0') << setw(3) << time << " �ܲ�: " << headquarterName << " ";
	cout << "����: " << warriorNames[position] << " ���:" << count << " ����ֵ: " << warriorValues[position];
	cout << " ͳ��: " << warriorCounts[position] << " " << warriorNames[position] << " in " << headquarterName << " headquarter" << endl;
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