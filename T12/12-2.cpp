#include <iostream>
#define N 5

using namespace std;

template <class T>
T Max(T value[], int size) {
	T max = value[0];
	for (int i = 1; i < size; ++i) {
		if (max < value[i]) {
			max = value[i];
		}
	}
	return max;
}

int main()
{
	int i, arr[N];	double dou[N];
	cout << "输入" << N << "个整数" << endl;
	for (i = 0; i < N; i++) cin >> arr[i];
	cout << "最大值为" << Max(arr, N) << endl;
	cout << "输入" << N << "个双精度型数据" << endl;
	for (i = 0; i < N; i++) cin >> dou[i];
	cout << "最大值为" << Max(dou, N) << endl;
	return 0;
}