#include "9-4.h"

int main()
{
	const int redOrder[5] = { 2,3,4,1,0 };					//红色总部的出兵顺序
	const int blueOrder[5] = { 3,0,1,2,4 };					//蓝色总部的出兵顺序
	const string headquartersNames[2] = { "RED","BLUE" };	//记录总部名字的数组
	const string priorNames[5] = { "dragon","ninja","iceman","lion","wolf" };//记录战士名字的数组
	int priorValue[5], headquartersValue, minValue, redPosition = 0, bluePosition = 0;
	bool redHadStop = false, blueHadStop = false;
	cout << "请输入总部生命值" << endl;
	cin >> headquartersValue;								//获取总部生命值
	cout << "请分别输入5种战士的生命值" << endl;
	for (int j = 0; j < 5; j++) { cin >> priorValue[j]; }	//获取每种战士的生命值
	//计算出战士中的最小生命值
	minValue = priorValue[0];
	for (int j = 1; j < 5; j++) { if (priorValue[j] < minValue) { minValue = priorValue[j]; } }
	//初始化红军总部和蓝军总部
	headquarters redOne = headquarters(headquartersValue, 0, priorValue, priorNames, redOrder, headquartersNames);
	headquarters blueOne = headquarters(headquartersValue, 1, priorValue, priorNames, blueOrder, headquartersNames);
	for (int time = 0; !redHadStop || !blueHadStop; ++time) {
	//如果红军没有停止出兵，继续
		if (!redHadStop) {
			//红军的生命值小于最小战士生命值， 停止出兵，打印命令
			if (redOne.getLifeValue() < minValue) {
				cout << setfill('0') << setw(3) << time << " RED headquarter stops making warriors" << endl;
				redHadStop = true;
			}
			else {
				//从上面的判断句筛选后，现在一定能出兵。
				//从当前position开始增加，到某个位置出兵了停止
				while (true) {
					if (redOne.getLifeValue() >= redOne.getWarriorValue(redPosition)) {
						redOne.product(time, redPosition);    //出兵
						if (redOne.getWarriorName(redPosition) == "dragon") {
							dragon theDragon(redOne.getCount(), redOne.getWarriorValue(redPosition), redOne.getLifeValue());
							theDragon.print();
						}
						else if (redOne.getWarriorName(redPosition) == "ninja") {
							ninja theNinja(redOne.getCount(), redOne.getWarriorValue(redPosition));
							theNinja.print();
						}
						else if (redOne.getWarriorName(redPosition) == "iceman") {
							iceman theIceman(redOne.getCount(), redOne.getWarriorValue(redPosition));
							theIceman.print();
						}
						else if (redOne.getWarriorName(redPosition) == "lion") {
							lion theLion(redOne.getCount(), redOne.getWarriorValue(redPosition), redOne.getLifeValue());
							theLion.print();
						}
						else {
							wolf theWolf(redOne.getCount(), redOne.getWarriorValue(redPosition));
						}
						//生产完当前战士，进入下一个战士
						if (redPosition == 4 ? redPosition = 0 : redPosition++);
						break;
					}
					//生命值不够生产当前战士，尝试下一个战士
					else { if (redPosition == 4 ? redPosition = 0 : redPosition++); }
				}
			}
		}
		if (!blueHadStop) {
			if (blueOne.getLifeValue() < minValue) {
				cout << setfill('0') << setw(3) << time << " BLUE headquarter stops making warriors" << endl;
				blueHadStop = true;
			}
			else {
				while (true) {
					if (blueOne.getLifeValue() >= blueOne.getWarriorValue(bluePosition)) {
						blueOne.product(time, bluePosition);
						if (blueOne.getWarriorName(bluePosition) == "dragon") {
							dragon theDragon(blueOne.getCount(), blueOne.getWarriorValue(bluePosition), blueOne.getLifeValue());
							theDragon.print();
						}
						else if (blueOne.getWarriorName(bluePosition) == "ninja") {
							ninja theNinja(blueOne.getCount(), blueOne.getWarriorValue(bluePosition));
							theNinja.print();
						}
						else if (blueOne.getWarriorName(bluePosition) == "iceman") {
							iceman theIceman(blueOne.getCount(), blueOne.getWarriorValue(bluePosition));
							theIceman.print();
						}
						else if (blueOne.getWarriorName(bluePosition) == "lion") {
							lion theLion(blueOne.getCount(), blueOne.getWarriorValue(bluePosition), blueOne.getLifeValue());
							theLion.print();
						}
						else { wolf theWolf(blueOne.getCount(), blueOne.getWarriorValue(bluePosition)); }
						if (bluePosition == 4 ? bluePosition = 0 : bluePosition++);
						break;
					}
					else { if (bluePosition == 4 ? bluePosition = 0 : bluePosition++); }
				}
			}
		}
	}
	return 0;
}
