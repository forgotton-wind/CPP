#include "9-4.h"

int main()
{
	const int redOrder[5] = { 2,3,4,1,0 };					//��ɫ�ܲ��ĳ���˳��
	const int blueOrder[5] = { 3,0,1,2,4 };					//��ɫ�ܲ��ĳ���˳��
	const string headquartersNames[2] = { "RED","BLUE" };	//��¼�ܲ����ֵ�����
	const string priorNames[5] = { "dragon","ninja","iceman","lion","wolf" };//��¼սʿ���ֵ�����
	int priorValue[5], headquartersValue, minValue, redPosition = 0, bluePosition = 0;
	bool redHadStop = false, blueHadStop = false;
	cout << "�������ܲ�����ֵ" << endl;
	cin >> headquartersValue;								//��ȡ�ܲ�����ֵ
	cout << "��ֱ�����5��սʿ������ֵ" << endl;
	for (int j = 0; j < 5; j++) { cin >> priorValue[j]; }	//��ȡÿ��սʿ������ֵ
	//�����սʿ�е���С����ֵ
	minValue = priorValue[0];
	for (int j = 1; j < 5; j++) { if (priorValue[j] < minValue) { minValue = priorValue[j]; } }
	//��ʼ������ܲ��������ܲ�
	headquarters redOne = headquarters(headquartersValue, 0, priorValue, priorNames, redOrder, headquartersNames);
	headquarters blueOne = headquarters(headquartersValue, 1, priorValue, priorNames, blueOrder, headquartersNames);
	for (int time = 0; !redHadStop || !blueHadStop; ++time) {
	//������û��ֹͣ����������
		if (!redHadStop) {
			//���������ֵС����Сսʿ����ֵ�� ֹͣ��������ӡ����
			if (redOne.getLifeValue() < minValue) {
				cout << setfill('0') << setw(3) << time << " RED headquarter stops making warriors" << endl;
				redHadStop = true;
			}
			else {
				//��������жϾ�ɸѡ������һ���ܳ�����
				//�ӵ�ǰposition��ʼ���ӣ���ĳ��λ�ó�����ֹͣ
				while (true) {
					if (redOne.getLifeValue() >= redOne.getWarriorValue(redPosition)) {
						redOne.product(time, redPosition);    //����
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
						//�����굱ǰսʿ��������һ��սʿ
						if (redPosition == 4 ? redPosition = 0 : redPosition++);
						break;
					}
					//����ֵ����������ǰսʿ��������һ��սʿ
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
