#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class Date {
public:
	Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
	void setDate(int y, int m, int d) { year = y;  month = m; day = d; }
	void showDate() { cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << " "; }
private:
	int year, month, day;
};

class Time {
public:
	Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
	void setTime(int h, int m, int s) { hour = h; minute = m; second = s; }
	void showTime() { cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second << endl; }
private:
	int hour, minute, second;
};

class DateTime : public Date, public Time {
public:
	DateTime(int y = 0, int mon = 0, int d = 0, int h = 0, int min = 0, int s = 0) :Date(y, mon, d), Time(h, min, s) { showDateTime(); }
	void setDateTime(int y, int mon, int d, int h, int min, int s) { setDate(y, mon, d); setTime(h, min ,s); }
	void showDateTime() { showDate(); showTime(); }
};

int main()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << "当前时间为: ";
	DateTime dt(sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);
	char c = 'n';
	int y, mon, d, h, min, s;
	cout << "是否修改日期和时间?(y/n): ";
	cin >> c;
	do {
		if (c == 'y') {
			cout << "输入新的日期和时间(年 月 日 时 分 秒): ";
			cin >> y >> mon >> d >> h >> min >> s;
			dt.setDateTime(y, mon, d, h, min, s);
			cout << "修改过的时间为: ";
			dt.showDateTime();
			cout << "是否继续修改?(y/n): ";
			cin >> c;
		}
	} while (c == 'y');
	return 0;
}