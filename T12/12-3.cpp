#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2, class T3>
class Output {
public:
	void display();
	Output(T1 d1, T2 d2, T3 d3) : data1(d1), data2(d2), data3(d3) {}
private:
	T1 data1;
	T2 data2;
	T3 data3;
};

template <class T1, class T2, class T3>
void Output<T1, T2, T3>::display()
{
	cout << data1 << "  " << data2 << "  " << data3 << endl;
}

int main()
{
	Output<int, int, float> o1(1, 2, 3.3);
	o1.display();
	Output<char, float, int> o2('A', 1.1, 2);
	o2.display();
	Output<string, string, string> o3("C++", "98", "·Ö");
	o3.display();
	return 0;
}