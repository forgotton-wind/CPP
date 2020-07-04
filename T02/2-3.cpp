#include <iostream>
using namespace std;

const int ArSize = 8;				//8皇后
int num = 0;						//解法数量
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
	cout << "八皇后问题共有" << num << "种解法！" << endl << endl;
	num = 0;
	int r, c;
	cout << "下面可以指定某一位置有皇后，查看此情况下解法总数" << endl;
	cout << "请输入一个确定皇后的位置" << endl;
	cout << "行(0~7)  ";
	cin >> r;
	cout << "列(0~7)  ";
	cin >> c;
	chessboard[r][c] = true;
	solve(chessboard, 0, r, c, 0);
	cout << "当输入坐标固定有一皇后时，有" << num << "种解法！" << endl;
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
		if (mode || (row != r || column != c)) arr[row][column] = false; //mode控制求全解还是固定位置的解
	}
}

bool check(bool arr[ArSize][ArSize], int row, int column)
{
	/*if (row == 0) {
		return true;
	}*/
	int i, j;
	// 判断纵向是否有冲突
	for (i = 0; i < row; ++i) {
		if (arr[i][column]) {
			return false;
		}
	}
	// 判断正斜对角线是否有冲突
	i = row - 1;
	j = column - 1;
	while (i >= 0 && j >= 0) {
		if (arr[i][j]) {
			return false;
		}
		--i;
		--j;
	}
	// 判断负斜对角线是否有冲突
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