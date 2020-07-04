#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

class CDate {
public:
	CDate(const CDate& d) :Year(d.Year), Month(d.Month), Day(d.Day) {}
	CDate(int y = 0, int m = 0, int d = 0) :Year(y), Month(m), Day(d) {}
	void SetDate(int y, int m, int d) { SetYear(y); SetMonth(m); SetDay(d); }
	inline void SetYear(int y) { this->Year = y; }
	inline void SetMonth(int m) { this->Month = m; }
	inline void SetDay(int d) { this->Day = d; }
	inline int GetYear() { return this->Year; }
	inline int GetMonth() { return this->Month; }
	inline int GetDay() { return this->Day; }
	inline void ShowDate(int format = 0);	//format=0:�����գ�format=1:�����꣬foramt=2:������

	void GetWeekNameofDate();
	void GetMonthNameofDate();
	bool IsLeapYear(int mode = 0);			//mode=0�����������������жϣ�mode=1������
	bool operator <(const CDate& d) const;
	bool operator <=(const CDate& d) const;
	bool operator >(const CDate& d) const;
	bool operator >=(const CDate& d) const;
	bool operator ==(const CDate& d) const;
	bool operator !=(const CDate& d) const;

	CDate& operator +(const CDate& d);
	CDate& operator -(const CDate& d);
	void operator ++(int);
	void operator --(int);

	friend ostream& operator <<(ostream& out, const CDate& d);
	friend istream& operator >>(istream& in, CDate& d);
protected:
	int Year, Month, Day;	//�ֱ����ꡢ�¡���
	enum WeekName { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
	enum MonthName { January = 1, February, March, April, May, June, July, August, September, October, November, December };
	int days1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};

class  CTime {
public:
	CTime(const CTime& d) :Hour(d.Hour), Minute(d.Minute), Second(d.Second) {}
	CTime(int h = 0, int m = 0, int s = 0) :Hour(h), Minute(m), Second(s) {}
	void SetTime(int h, int m, int s) { SetHour(h); SetMinute(m); SetSecond(s); }
	inline void SetHour(int h) { Hour = h; }
	inline void SetMinute(int m) { Minute = m; }
	inline void SetSecond(int s) { Second = s; }
	inline int GetHour() { return Hour; }
	inline int GetMinute() { return Minute; }
	inline int GetSecond() { return Second; }
	inline void ShowTime(int format = 0);	//format=0:24Сʱ�ƣ�format=1:12Сʱ��

	bool operator <(const CTime& t) const;
	bool operator <=(const CTime& t) const;
	bool operator >(const CTime& t) const;
	bool operator >=(const CTime& t) const;
	bool operator ==(const CTime& t) const;
	bool operator !=(const CTime& t) const;

	CTime& operator +(const CTime& t);
	CTime& operator -(const CTime& t);
	void operator ++(int);
	void operator --(int);

	friend ostream& operator <<(ostream& out, const CTime& t);
	friend istream& operator >>(istream& in, CTime& t);
protected:
	int Hour, Minute, Second; //�ֱ���ʱ���֡���
};

class CDateTime :public CDate, public CTime{
public:
	CDateTime(int y = 0, int mon = 0, int d = 0, int h = 0, int min = 0, int s = 0) :CDate(y, mon, d), CTime(h, min, s) {}
	void SetDateTime(int y = 0, int mon = 0, int d = 0, int h = 0, int min = 0, int s = 0) {
		SetDate(y, mon, d);
		SetTime(h, min, s);
	}
	//format1=0:�����գ�format1=1:�����꣬foramt1=2:������
	//format2=0:24Сʱ�ƣ�format2=1:12Сʱ��
	inline void ShowDateTime(int format1 = 0, int format2 = 0);

	bool operator <(const CDateTime& c) const;
	bool operator <=(const CDateTime& c) const;
	bool operator >(const CDateTime& c) const;
	bool operator >=(const CDateTime& c) const;
	bool operator ==(const CDateTime& c) const;
	bool operator !=(const CDateTime& c) const;

	CDateTime& operator +(const CDateTime& c);
	CDateTime& operator -(const CDateTime& c);

	friend ostream& operator <<(ostream& out, const CDateTime& c);
	friend istream& operator >>(istream& in, CDateTime& c);
};

void CDate::ShowDate(int format)
{
	if (format == 0) {
		cout << setw(4) << setfill('0') << Year << "-" << setw(2) << setfill('0') << Month << "-" 
			 << setw(2) << setfill('0') << Day << endl;
	}
	else if (format == 1) {
		cout << setw(4) << setfill('0') << Month << "-" << setw(2) << setfill('0') << Day << "-"
			 << setw(2) << setfill('0') << Year << endl;
	}
	else if (format == 2) {
		cout << setw(4) << setfill('0') << Day << "-" << setw(2) << setfill('0') << Month << "-"
			<< setw(2) << setfill('0') << Year << endl;
	}
}

void CDate::GetMonthNameofDate()
{
	switch (this->Month) {
	case January:
		puts("January");
		break;
	case February:
		puts("February");
		break;
	case March:
		puts("March");
		break;
	case April:
		puts("April");
		break;
	case May:
		puts("May");
		break;
	case June:
		puts("June");
		break;
	case July:
		puts("July");
		break;
	case August:
		puts("August");
		break;
	case September:
		puts("September");
		break;
	case October:
		puts("October");
		break;
	case November:
		puts("November");
		break;
	case December:
		puts("December");
		break;
	}
}

void CDate::GetWeekNameofDate()
{
	int Year_copy = Year;
	int d = Day;
	int m = Month;
	if (m == 1 || m == 2) {
		m += 12;
		Year_copy -= 1;
	}
	int y = Year_copy % 100;
	int c = Year_copy / 100;
	int w = y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
	while (w < 0) {
		w += 7;
	}
	switch (w % 7) {
	case Sunday:
		puts("Sunday");
		break;
	case Monday:
		puts("Monday");
		break;
	case Tuesday:
		puts("Tuesday");
		break;
	case Wednesday:
		puts("Wednesday");
		break;
	case Thursday:
		puts("Thursday");
		break;
	case Friday:
		puts("Friday");
		break;
	case Saturday:
		puts("Saturday");
		break;
	}
}

bool CDate::IsLeapYear(int mode)
{
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0) {
		if (mode == 1) cout << "������" << endl;
		return true;
	}
	if (mode == 1) cout << "��ƽ��" << endl;
	return false;
}

bool CDate::operator <(const CDate& d) const
{
	if (this->Year < d.Year) return true;
	else if (this->Year > d.Year) return false;
	else {
		if (this->Month < d.Month) return true;
		else if (this->Month > d.Month) return false;
		else {
			if (this->Day < d.Day) return true;
			else return false;
		}
	}
}

bool CDate::operator >(const CDate& d) const
{
	if (this->Year > d.Year) return true;
	else if (this->Year < d.Year) return false;
	else {
		if (this->Month > d.Month) return true;
		else if (this->Month < d.Month) return false;
		else {
			if (this->Day > d.Day) return true;
			else return false;
		}
	}
}

bool CDate::operator ==(const CDate& d) const
{
	if (this->Year != d.Year) return false;
	else {
		if (this->Month != d.Month) return false;
		else {
			if (this->Day == d.Day) return true;
			else return false;
		}
	}
}

bool CDate::operator <=(const CDate& d) const
{
	if (this->Year > d.Year) return false;
	else if (this->Year < d.Year) return true;
	else {
		if (this->Month > d.Month) return false;
		else if (this->Month < d.Month) return true;
		else {
			if (this->Day <= d.Day) return true;
			else return false;
		}
	}
}

bool CDate::operator >=(const CDate& d) const
{
	if (this->Year < d.Year) return false;
	else if (this->Year > d.Year) return true;
	else {
		if (this->Month < d.Month) return false;
		else if (this->Month > d.Month) return true;
		else {
			if (this->Day >= d.Day) return true;
			else return false;
		}
	}
}

bool CDate::operator !=(const CDate& d) const
{
	if (this->Year != d.Year) return true;
	else {
		if (this->Month != d.Month) return true;
		else {
			if (this->Day != d.Day) return true;
			else return false;
		}
	}
}

CDate& CDate::operator +(const CDate& d)
{
	this->Year += d.Year;
	this->Month += d.Month - 1;
	this->Day += d.Day - 1;
	if (this->Month > 12) {
		this->Month -= 12;
		this->Year += 1;
	}
	int* a;
	if (this->IsLeapYear()) a = days2;
	else a = days1;
	while (this->Day > a[this->Month - 1]) {
		this->Day -= a[this->Month - 1];
		this->Month++;
		if (this->Month > 12) {
			this->Month -= 12;
			this->Year += 1;
		}
	}
	return (*this);
}

CDate& CDate::operator -(const CDate& d)
{
	this->Year -= d.Year;
	this->Month -= d.Month - 1;
	this->Day -= d.Day - 1;
	if (this->Month < 1) {
		this->Month += 12;
		this->Year -= 1;
	}
	int* a;
	if (this->IsLeapYear()) a = days2;
	else a = days1;
	while (this->Day < 1) {
		this->Day += a[this->Month - 2];
		this->Month--;
		if (this->Month < 1) {
			this->Month += 12;
			this->Year -= 1;
		}
	}
	return (*this);
}

void CDate::operator ++(int)
{
	int* a;
	if (this->IsLeapYear()) a = days2;
	else a = days1;
	this->Day++;
	if (this->Day > a[this->Month - 1]) {
		this->Day = 1;
		this->Month++;
	}
	if (this->Month > 12) {
		this->Month = 1;
		this->Year++;
	}
}

void CDate::operator --(int)
{
	int* a;
	if (this->IsLeapYear()) a = days2;
	else a = days1;
	this->Day--;
	if (this->Day < 1) {
		this->Month--;
		this->Day = a[this->Month - 1];
	}
	if (this->Month < 1) {
		this->Month = 12;
		this->Year--;
	}
}

void CTime::ShowTime(int format)
{
	if (format == 0) {
		cout << setw(2) << setfill('0') << Hour << ":" << setw(2) << setfill('0') << Minute << ":"
			<< setw(2) << setfill('0') << Second << endl;
	}
	else if (format == 1) {
		cout << setw(2) << setfill('0') << Hour % 12 << ":" << setw(2) << setfill('0') << Minute << ":"
			<< setw(2) << setfill('0') << Second << endl;
	}
}

bool CTime::operator <(const CTime& t) const
{
	if (this->Hour < t.Hour) return true;
	else if (this->Hour > t.Hour) return false;
	else {
		if (this->Minute < t.Minute) return true;
		else if (this->Minute > t.Minute) return false;
		else {
			if (this->Second < t.Second) return true;
			else return false;
		}
	}
}

bool CTime::operator >(const CTime& t) const
{
	if (this->Hour > t.Hour) return true;
	else if (this->Hour < t.Hour) return false;
	else {
		if (this->Minute > t.Minute) return true;
		else if (this->Minute < t.Minute) return false;
		else {
			if (this->Second > t.Second) return true;
			else return false;
		}
	}
}

bool CTime::operator <=(const CTime& t) const
{
	if (this->Hour < t.Hour) return true;
	else if (this->Hour > t.Hour) return false;
	else {
		if (this->Minute < t.Minute) return true;
		else if (this->Minute > t.Minute) return false;
		else {
			if (this->Second <= t.Second) return true;
			else return false;
		}
	}
}

bool CTime::operator >=(const CTime& t) const
{
	if (this->Hour > t.Hour) return true;
	else if (this->Hour < t.Hour) return false;
	else {
		if (this->Minute > t.Minute) return true;
		else if (this->Minute < t.Minute) return false;
		else {
			if (this->Second >= t.Second) return true;
			else return false;
		}
	}
}

bool CTime::operator ==(const CTime& t) const
{
	if (this->Hour != t.Hour) return false;
	else {
		if (this->Minute != t.Minute) return false;
		else {
			if (this->Second == t.Second) return true;
			else return false;
		}
	}
}

bool CTime::operator !=(const CTime& t) const
{
	if (this->Hour != t.Hour) return true;
	else {
		if (this->Minute != t.Minute) return true;
		else {
			if (this->Second == t.Second) return false;
			else return true;
		}
	}
}

void CTime::operator ++(int)
{
	this->Second++;
	if (this->Second == 60) {
		this->Second = 0;
		this->Minute++;
	}
	if (this->Minute == 60) {
		this->Minute = 0;
		this->Hour++;
	}
	if (this->Hour == 24) {
		this->Hour = 0;
	}
}

void CTime::operator --(int)
{
	this->Second--;
	if (this->Second < 0) {
		this->Second = 59;
		this->Minute--;
	}
	if (this->Minute < 0) {
		this->Minute = 59;
		this->Hour--;
	}
	if (this->Hour < 0) {
		this->Hour = 23;
	}
}

CTime& CTime::operator +(const CTime& t)
{
	this->Hour += t.Hour;
	this->Minute += t.Minute;
	this->Second += t.Second;
	if (this->Second >= 60) {
		this->Second -= 60;
		this->Minute++;
	}
	if (this->Minute >= 60) {
		this->Minute -= 60;
		this->Hour++;
	}
	if (this->Hour >= 24) {
		this->Hour -= 24;
	}
	return (*this);
}

CTime& CTime::operator -(const CTime& t)
{
	this->Hour -= t.Hour;
	this->Minute -= t.Minute;
	this->Second -= t.Second;
	if (this->Second < 0) {
		this->Second += 60;
		this->Minute--;
	}
	if (this->Minute < 0) {
		this->Minute += 60;
		this->Hour--;
	}
	if (this->Hour < 0) {
		this->Hour += 24;
	}
	return (*this);
}

void CDateTime::ShowDateTime(int format1, int format2)
{
	if (format1 == 0) {
		cout << setw(4) << setfill('0') << Year << "-" << setw(2) << setfill('0') << Month << "-"
			<< setw(2) << setfill('0') << Day;
	}
	else if (format1 == 1) {
		cout << setw(4) << setfill('0') << Month << "-" << setw(2) << setfill('0') << Day << "-"
			<< setw(2) << setfill('0') << Year;
	}
	else if (format1 == 2) {
		cout << setw(4) << setfill('0') << Day << "-" << setw(2) << setfill('0') << Month << "-"
			<< setw(2) << setfill('0') << Year;
	}
	cout << " ";
	if (format2 == 0) {
		cout << setw(2) << setfill('0') << Hour << ":" << setw(2) << setfill('0') << Minute << ":"
			<< setw(2) << setfill('0') << Second << endl;
	}
	else if (format2 == 1) {
		cout << setw(2) << setfill('0') << Hour % 12 << ":" << setw(2) << setfill('0') << Minute << ":"
			<< setw(2) << setfill('0') << Second << endl;
	}
}

bool CDateTime::operator <(const CDateTime& c) const
{
	CDate d1(this->Year, this->Month, this->Day), d2(c.Year, c.Month, c.Day);
	CTime t1(this->Hour, this->Minute, this->Second), t2(c.Hour, c.Minute, c.Second);
	if (d1 < d2) return true;
	else if (d1 > d2) return false;
	else {
		if (t1 < t2) return true;
		else return false;
	}
}

bool CDateTime::operator >(const CDateTime& c) const
{
	CDate d1(this->Year, this->Month, this->Day), d2(c.Year, c.Month, c.Day);
	CTime t1(this->Hour, this->Minute, this->Second), t2(c.Hour, c.Minute, c.Second);
	if (d1 > d2) return true;
	else if (d1 < d2) return false;
	else {
		if (t1 > t2) return true;
		else return false;
	}
}

bool CDateTime::operator <=(const CDateTime& c) const
{
	CDate d1(this->Year, this->Month, this->Day), d2(c.Year, c.Month, c.Day);
	CTime t1(this->Hour, this->Minute, this->Second), t2(c.Hour, c.Minute, c.Second);
	if (d1 < d2) return true;
	else if (d1 > d2) return false;
	else {
		if (t1 <= t2) return true;
		else return false;
	}
}

bool CDateTime::operator >=(const CDateTime& c) const
{
	CDate d1(this->Year, this->Month, this->Day), d2(c.Year, c.Month, c.Day);
	CTime t1(this->Hour, this->Minute, this->Second), t2(c.Hour, c.Minute, c.Second);
	if (d1 > d2) return true;
	else if (d1 < d2) return false;
	else {
		if (t1 >= t2) return true;
		else return false;
	}
}

bool CDateTime::operator ==(const CDateTime& c) const
{
	CDate d1(this->Year, this->Month, this->Day), d2(c.Year, c.Month, c.Day);
	CTime t1(this->Hour, this->Minute, this->Second), t2(c.Hour, c.Minute, c.Second);
	if (d1 != d2) return false;
	else {
		if (t1 == t2) return true;
		else return false;
	}
}

bool CDateTime::operator !=(const CDateTime& c) const
{
	CDate d1(this->Year, this->Month, this->Day), d2(c.Year, c.Month, c.Day);
	CTime t1(this->Hour, this->Minute, this->Second), t2(c.Hour, c.Minute, c.Second);
	if (d1 != d2) return true;
	else {
		if (t1 != t2) return true;
		else return false;
	}
}

CDateTime& CDateTime::operator +(const CDateTime& c)
{
	this->Hour += c.Hour;
	this->Minute += c.Minute;
	this->Second += c.Second;
	if (this->Second >= 60) {
		this->Second -= 60;
		this->Minute++;
	}
	if (this->Minute >= 60) {
		this->Minute -= 60;
		this->Hour++;
	}
	if (this->Hour >= 24) {
		this->Hour -= 24;
		this->Day++;
	}
	this->Year += c.Year;
	this->Month += c.Month - 1;
	this->Day += c.Day - 1;
	if (this->Month > 12) {
		this->Month -= 12;
		this->Year += 1;
	}
	int* a;
	if (this->IsLeapYear()) a = days2;
	else a = days1;
	while (this->Day > a[this->Month - 1]) {
		this->Day -= a[this->Month - 1];
		this->Month++;
		if (this->Month > 12) {
			this->Month -= 12;
			this->Year += 1;
		}
	}
	return (*this);
}

CDateTime& CDateTime::operator -(const CDateTime& c)
{
	this->Hour -= c.Hour;
	this->Minute -= c.Minute;
	this->Second -= c.Second;
	if (this->Second < 0) {
		this->Second += 60;
		this->Minute--;
	}
	if (this->Minute < 0) {
		this->Minute += 60;
		this->Hour--;
	}
	if (this->Hour < 0) {
		this->Hour += 24;
		this->Day--;
	}
	this->Year -= c.Year;
	this->Month -= c.Month - 1;
	this->Day -= c.Day - 1;
	if (this->Month < 1) {
		this->Month += 12;
		this->Year -= 1;
	}
	int* a;
	if (this->IsLeapYear()) a = days2;
	else a = days1;
	while (this->Day < 1) {
		this->Day += a[this->Month - 2];
		this->Month--;
		if (this->Month < 1) {
			this->Month += 12;
			this->Year -= 1;
		}
	}
	return (*this);
}

int main()
{
	CDate d(2020, 5, 18), d2;
	cout << "����1: "; d.ShowDate();
	cout << "�·�: "; d.GetMonthNameofDate();
	cout << "����: "; d.GetWeekNameofDate();
	d.IsLeapYear(1); cout << endl;

	d2 = d;
	d.SetDate(2051, 9, 9);
	cout << "����2: "; d.ShowDate();
	cout << "�·�: "; d.GetMonthNameofDate();
	cout << "����: "; d.GetWeekNameofDate();
	d.IsLeapYear(1); cout << endl;

	if (d2 < d) {
		cout << "����1������2С" << endl;
	}
	else if (d2 == d) {
		cout << "����1������2���" << endl;
	}
	else if (d2 > d) {
		cout << "����1������2��" << endl;
	}
	cout << "����������ӵ�ʱ�����: " << "(ע��:�˴����Ϊ0000-01-01Ϊ0����,��1��1�ռӵ��κ�ʱ�䶼���ֲ���)" << endl;
	(d2 + d).ShowDate();
	d2.SetDate(2020, 5, 18);
	cout << "�������������ʱ�����: " << "(ע��:�˴����Ϊ0000-01-01Ϊ0����,��1��1�ձ������κ�ʱ�䶼���ֲ���)" << endl;
	(d - d2).ShowDate();
	
	d2++;
	cout << endl << "����1����һ������: " << endl;
	d2.ShowDate();
	d2--;
	cout << "��������һ������: " << endl;
	d2.ShowDate();

	CTime t(20, 58, 34), t2;
	cout << endl << "ʱ��1: ";
	t.ShowTime();
	t2++;
	cout << "ʱ��1����һ�����:";
	t2.ShowTime();

	t2 = t;
	t.SetTime(22, 34, 48);
	cout << "ʱ��2: ";
	t.ShowTime();
	t--;
	cout << "ʱ��2����һ�����:";
	t.ShowTime();

	t2.SetTime(22, 34, 48);
	t.SetTime(20, 58, 34);
	if (t2 < t) {
		cout << "ʱ��1��ʱ��2С" << endl;
	}
	else if (t2 > t) {
		cout << "ʱ��1��ʱ��2��" << endl;
	}
	else {
		cout << "ʱ��1��ʱ��2���" << endl;
	}
	cout << "ʱ��1��ʱ��2�ĺ�Ϊ: ";
	(t2 + t).ShowTime();
	t2.SetTime(22, 34, 48);
	cout << "ʱ��2��ʱ��1�Ĳ�Ϊ: ";
	(t2 - t).ShowTime();
	cout << endl;

	cout << "����&ʱ��1: ";
	CDateTime c(2020, 5, 21, 21, 33, 02), c2;
	c.ShowDateTime();
	cout << "����&ʱ��2: ";
	c2.SetDateTime(2077, 7, 7, 8, 0, 0);
	c2.ShowDateTime();

	if (c < c2) cout << "����1������2С" << endl;
	else if (c > c2) cout << "����1������2��" << endl;
	else cout << "����1������2���" << endl;

	cout << "����1������2�ĺ�Ϊ: ";
	(c + c2).ShowDateTime();
	c.SetDateTime(2020, 5, 21, 21, 33, 02);
	cout << "����2������1�Ĳ�Ϊ: ";
	(c2 - c).ShowDateTime();
	return 0;
}