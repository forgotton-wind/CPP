#include <iostream>
using namespace std;

const int ArSize = 8;				//8�ʺ�
int num = 0;						//�ⷨ����
void solve(bool arr[ArSize][ArSize], int row, int r, int c, int mode);
bool check(bool arr[ArSize][ArSize], int row, int column);
void outPut(bool arr[ArSize][ArSize]);
int main()
{
	bool chessboard[ArSize][ArSize];
	for (int i = 0; i < ArSize; i++) {
		for (int j = 0; j < ArSize; j++) {
			chessboard[i][j] = false;
		}
	}
	solve(chessboard, 0, 0, 0, 1);
	cout << "�˻ʺ����⹲��" << num << "�ֽⷨ��" << endl << endl;
	num = 0;
	int r, c;
	cout << "�������ָ��ĳһλ���лʺ󣬲鿴������½ⷨ����" << endl;
	cout << "������һ��ȷ���ʺ��λ��" << endl;
	cout << "��(0~7)  ";
	cin >> r;
	cout << "��(0~7)  ";
	cin >> c;
	chessboard[r][c] = true;
	solve(chessboard, 0, r, c, 0);
	cout << "����������̶���һ�ʺ�ʱ����" << num << "�ֽⷨ��" << endl;
	return 0;
}

void solve(bool arr[ArSize][ArSize], int row, int r, int c, int mode)
{
	for (int column = 0; column < ArSize; ++column) {
		arr[row][column] = true;
		if (check(arr, row, column)) {
			if (row == ArSize - 1) {
				outPut(arr);
			} 
			else{
				solve(arr, row + 1, r, c, mode);
			}
		}
		if (mode || (row != r || column != c)) arr[row][column] = false; //mode������ȫ�⻹�ǹ̶�λ�õĽ�
	}
}

bool check(bool arr[ArSize][ArSize], int row, int column)
{
	/*if (row == 0) {
		return true;
	}*/
	int i, j;
	// �ж������Ƿ��г�ͻ
	for (i = 0; i < row; ++i) {
		if (arr[i][column]) {
			return false;
		}
	}
	// �ж���б�Խ����Ƿ��г�ͻ
	i = row - 1;
	j = column - 1;
	while (i >= 0 && j >= 0) {
		if (arr[i][j]) {
			return false;
		}
		--i;
		--j;
	}
	// �жϸ�б�Խ����Ƿ��г�ͻ
	i = row - 1;
	j = column + 1;
	while (i >= 0 && j < ArSize) {
		if (arr[i][j]) {
			return false;
		}
		--i;
		++j;
	}
	return true;
}

void outPut(bool arr[ArSize][ArSize])
{
	++num;
	cout << "**********************" << num << "*********************" << endl;
	for (int i = 0; i < ArSize; ++i) {
		for (int j = 0; j < ArSize; ++j) {
			if (arr[i][j]) cout << "x" << " ";
			else cout << "." << " ";
		}
		cout << endl;
	}
	cout << "*********************************************" << endl;
}