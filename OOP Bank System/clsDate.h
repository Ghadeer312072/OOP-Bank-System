#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<iomanip>
#include"clsString.h"


using namespace std;
class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;
public:
	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;
	}
	clsDate(string Date) {
		vector<string> vDate;
		vDate = clsString::Split(Date, "/");
		Day = stoi(vDate[2]);
		Month = stoi(vDate[1]);
		Year = stoi(vDate[0]);
	}
	clsDate(short year, short month, short day) {
		Day = day;
		Month = month;
		Year = year;
	}
	clsDate(short days, short year) {
		clsDate Date = getDateFromDays(days, year);
		Day = Date.Day;
		Month = Date.Month;
		Year = Date.Year;
	}
	void setDay(short Day) {
		_Day = Day;
	}
	short getDay() {
		return _Day;
	}
	void setMonth(short Month) {
		_Month = Month;
	}
	short getMonth() {
		return _Month;
	}
	void setyear(short year) {
		_Year = year;
	}
	short getYear() {
		return _Year;
	}
	__declspec(property(get = getDay, put = setDay)) short Day;
	__declspec(property(get = getMonth, put = setMonth)) short Month;
	__declspec(property(get = getYear, put = setyear)) short Year;
	static clsDate GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		short day, month, year;
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
		return clsDate(year, month, day);
	}

	static bool ISValid(clsDate date) {
		if (date.Year < 0)return false;
		if (date.Month == 2 && date.Day > 29)return false;
		if (!IsLeapYear(date.Year) && date.Month == 2 && date.Day > 28)return false;
		if (date.Month < 1 || date.Month>12)return false;
		if (date.Day < 1 || date.Day>31)return false;
		if (date.Day > DaysInMonth(date.Year, date.Month))return false;
		return true;
	}
	bool ISValid() {
		return ISValid(*this);
	}

	static bool IsLeapYear(short year) {
		return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
	}
	bool IsLeapYear() {
		return IsLeapYear(Year);
	}
	static string DateToString(clsDate date) {
		return to_string(date.Year) + '/' + to_string(date.Month) + '/' + to_string(date.Day);
	}
	string DateToString() {
		return DateToString(*this);
	}
	static short NumberOfDaysInYear(short year) {
		return IsLeapYear(year) ? 366 : 365;
	}
	short NumberOfDaysInYear() {
		return NumberOfDaysInYear(Year);
	}
	static short NumberOfHoursInYear(short year) {
		return NumberOfDaysInYear(year) * 24;
	}
	short NumberOfHoursInYear() {
		return NumberOfHoursInYear(Year);
	}
	static int NumberOfminutesInYear(short year) {
		return NumberOfHoursInYear(year) * 60;
	}
	int NumberOfminutesInYear() {
		return NumberOfminutesInYear(Year);
	}
	static int NumberOfSecandInYear(short year) {
		return NumberOfminutesInYear(year) * 60;
	}
	int NumberOfSecandInYear() {
		return NumberOfSecandInYear(Year);
	}
	static short DaysInMonth(short year, short month) {
		short MonthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month > 12 || month < 1)return 0;
		return (IsLeapYear(year) && month == 2) ? 29 : MonthDays[month - 1];
	}
	short DaysInMonth() {
		return DaysInMonth(Year, Month);
	}
	static short NumberOfHoursInMonth(short year, short month) {
		return DaysInMonth(year, month) * 24;
	}
	short NumberOfHoursInMonth() {
		return NumberOfHoursInMonth(Year, Month);
	}
	static int NumberOfMinutesInMonth(short year, short month) {
		return NumberOfHoursInMonth(year, month) * 60;
	}
	int NumberOfMinutesInMonth() {
		return NumberOfMinutesInMonth(Year, Month);
	}
	static int NumberOfSecandOfMonth(short year, short month) {
		return NumberOfMinutesInMonth(year, month) * 60;
	}
	int NumberOfSecandOfMonth() {
		return NumberOfSecandOfMonth(Year, Month);
	}
	static clsDate getDateFromDays(short days, short year) {
		clsDate obj;
		short month = 1;
		obj.Year = year;
		while (true) {
			if (days > DaysInMonth(month, year)) {
				days -= DaysInMonth(month, year);
				obj.Month++;
				month++;
			}
			else {
				obj.Day = days;
				break;
			}
		}
		return obj;
	}

	static short DayOrderInWeek(short year, short month, short day) {
		short a, y, m, d;
		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;
		d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}
	short DayOrderInWeek() {
		return DayOrderInWeek(Year, Month, Day);
	}
	static string DayName(short day) {
		string weekDays[] = { "sun","mon","tus","win","thr","fri","sat" };
		return weekDays[day];
	}
	string DayName() {
		return DayName(DayOrderInWeek());
	}
	static string MonthName(short month) {
		string monthsName[12] = {
		"Jan", "Feb", "Mar", "Apr",
		"May", "Jun", "Jul", "Aug",
		"Sep", "Oct", "Nov", "Dec"
		};
		return monthsName[month - 1];
	}
	string MonthName() {
		return MonthName(Month);
	}


	static  void PrintMonthCalender(short year, short month) {
		short day = DayOrderInWeek(year, month, 1);
		cout << "\n_________________" << MonthName(month) << "_________________\n";
		for (short i = 1; i <= 7; i++) {
			cout << setw(5) << DayName(i);
		}
		cout << endl;
		for (short i = 0; i < day; i++) {
			cout << setw(5) << " ";
		}
		short daysInWeek = day;
		for (short i = 1; i <= DaysInMonth(year, month); i++) {
			if (daysInWeek == 7) {
				cout << endl;
				daysInWeek = 0;
			}
			cout << setw(5) << i;
			daysInWeek++;
		}
		cout << "\n___________________________________________________\n";
	}
	void PrintMonthCalender() {
		PrintMonthCalender(Year, Month);
	}
	static void PrintyearCalender(short year) {
		cout << "\n___________________" << year << "___________________" << endl;
		for (short i = 1; i <= 12; i++) {
			PrintMonthCalender(year, i);
		}
		cout << "\n___________________________________________________\n";
	}
	void PrintyearCalender() {
		PrintyearCalender(Year);
	}


	static short DaysFromYearBegin(short year, short month, short day) {
		short days = 0;
		for (short i = 1; i < month; i++) {
			days += DaysInMonth(year, i);
		}
		days += day;
		return days;
	}
	short DaysFromYearBegin() {
		return DaysFromYearBegin(Year, Month, Day);
	}
	void addDays(short Days) {
		int days = Days + DaysFromYearBegin(Year, Month, Day);
		Month = 1;
		while (true) {
			if (days > DaysInMonth(Year, Month)) {
				days -= DaysInMonth(Year, Month);
				++Month;
				if (Month > 12) {
					Year++;
					Month = 1;
				}
			}
			else {
				Day = days;
				break;
			}

		}

	}


	static clsDate addOneDay(clsDate date) {
		if (isLastDayInMonth(date)) {
			if (isLastMonthInYear(date)) {
				date.Year++;
				date.Day = 1;
				date.Month = 1;
			}
			else {
				date.Month++;
				date.Day = 1;
			}
		}
		else {
			date.Day++;
		}
		return date;
	}
	void addOneDay() {
		*this = addOneDay(*this);
	}
	static bool Date1BeforDate2(clsDate date1, clsDate date2) {
		return date1.Year < date2.Year ? true : (
			date1.Year == date2.Year ? (
				date1.Month < date2.Month ? true : (
					date1.Month == date2.Month ? (
						date1.Day < date2.Day ? true :
						false
						) : false
					)
				) : false);

	}
	bool DateBeforDate2(clsDate date) {
		return Date1BeforDate2(*this, date);
	}
	static bool Date1EqualDate2(clsDate date1, clsDate date2) {
		return	date1.Year == date2.Year ? (
			date1.Month == date2.Month ?
			(date1.Day == date2.Day ? true : false) : false
			) : false;

	}
	bool DateEqualDate2(clsDate date) {
		return Date1EqualDate2(date, *this);
	}
	static bool isLastDayInMonth(clsDate date) {
		return date.Day == DaysInMonth(date.Year, date.Month);
	}
	bool isLastDayInMonth() {
		return isLastDayInMonth(*this);
	}
	static bool isLastMonthInYear(clsDate date) {
		return date.Month == 12;
	}
	bool isLastMonthInYear() {
		return isLastMonthInYear(*this);
	}
	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Date;
		Date.Year = Date1.Year;
		Date1.Year = Date2.Year;
		Date2.Year = Date.Year;

		Date.Month = Date1.Month;
		Date1.Month = Date2.Month;
		Date2.Month = Date.Month;

		Date.Day = Date1.Day;
		Date1.Day = Date2.Day;
		Date2.Day = Date.Day;
	}

	static short GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		short Days = 0;
		short SwapFlag = 1;
		if (!Date1BeforDate2(Date1, Date2)) {
			SwapDates(Date1, Date2);
			//SwapFlag = -1;
		}
		while (Date1BeforDate2(Date1, Date2)) {
			Days++;
			Date1 = addOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlag : Days * SwapFlag;
	}
	short GetDifferenceInDays(clsDate Date, bool IncludeEndDay = false) {
		return  GetDifferenceInDays(*this, Date, IncludeEndDay);
	}

	static clsDate IncreaseDateByXDays(clsDate Date, short Days) {
		for (short i = 1; i <= Days; i++) {
			Date = addOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short days) {
		*this = IncreaseDateByXDays(*this, days);
	}
	static clsDate IncreaseDateByOneWeek(clsDate Date) {
		for (short i = 1; i <= 7; i++) {
			Date = addOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByOneWeek() {
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate Date, short NumberOfWeek) {
		for (short i = 1; i <= NumberOfWeek; i++) {
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short NumberOfWeek) {
		*this = IncreaseDateByXWeeks(*this, NumberOfWeek);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date) {
		if (Date.Month == 12) {
			Date.Year++;
			Date.Month = 1;
		}
		else {
			Date.Month++;
		}
		short DaysInCurrentMonth = DaysInMonth(Date.Year, Date.Month);
		if (Date.Day > DaysInCurrentMonth) {
			Date.Day = DaysInMonth(Date.Year, Date.Month);
		}
		return Date;
	}
	void IncreaseDateByOneMonth() {
		*this = IncreaseDateByOneMonth(*this);
	}


	static void IncreaseDateByXMonth(clsDate& Date, short NumberOfMonth) {
		for (short i = 1; i <= NumberOfMonth; i++) {
			Date = IncreaseDateByOneMonth(Date);
		}
	}
	void IncreaseDateByXMonth(short NumberOfMonth) {
		IncreaseDateByXMonth(*this, NumberOfMonth);
	}

	static void IncreaseDateByOneYear(clsDate& Date) {

		if (Date.Day == DaysInMonth(Date.Year, Date.Month)) {
			Date.Year++;
			Date.Day = DaysInMonth(Date.Year, Date.Month);
		}
		else {
			Date.Year++;
		}
	}
	void IncreaseDateByOneYear() {
		IncreaseDateByOneYear(*this);
	}

	static void IncreaseDateByXYear(clsDate& Date, short NumberOfYears) {
		for (short i = 1; i <= NumberOfYears; i++) {
			IncreaseDateByOneYear(Date);
		}

	}
	void IncreaseDateByXYear(short NumberOfYears) {
		IncreaseDateByXYear(*this, NumberOfYears);
	}
	static bool IsFirstDayInMonth(clsDate Date) {
		return Date.Day == 1;
	}
	static bool IsFirstMonthInYear(clsDate Date) {
		return Date.Month == 1;
	}
	static clsDate DecreaseDateByOneDay(clsDate& Date) {
		if (IsFirstDayInMonth(Date)) {
			if (IsFirstMonthInYear(Date)) {
				Date.Year--;
				Date.Month = 12;
				Date.Day = 31;
			}
			else {
				Date.Month--;
				Date.Day = DaysInMonth(Date.Year, Date.Month);
			}
		}
		else {
			Date.Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay() {
		DecreaseDateByOneDay(*this);
	}
	static clsDate DecreaseDateByXDays(clsDate& Date, short Days) {
		for (short i = 1; i <= Days; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days) {
		DecreaseDateByXDays(*this, Days);
	}
	static clsDate DecreaseDateByOneWeek(clsDate& Date) {
		for (short i = 1; i <= 7; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeek() {
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate& Date, short NumberOfWeek) {
		for (short i = 1; i <= NumberOfWeek; i++) {
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short NumberOfWeek) {
		DecreaseDateByXWeeks(*this, NumberOfWeek);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date) {
		if (IsFirstMonthInYear(Date)) {
			Date.Year--;
			Date.Month = 12;
		}
		else {
			Date.Month--;
		}

		if (Date.Day > DaysInMonth(Date.Year, Date.Month))
			Date.Day = DaysInMonth(Date.Year, Date.Month);

		return Date;
	}

	void DecreaseDateByOneMonth() {
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonth(clsDate& Date, short NumberOfMonth) {
		for (short i = 1; i <= NumberOfMonth; i++) {
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonth(short NumberOfMonth) {
		DecreaseDateByXMonth(*this, NumberOfMonth);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date) {

		if (isLastDayInMonth(Date)) {
			Date.Year--;
			Date.Day = DaysInMonth(Date.Year, Date.Month);
		}
		else {
			Date.Year--;
		}
		return Date;
	}

	void DecreaseDateByOneYear() {
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYear(clsDate& Date, short NumberOfYears) {
		for (short i = 1; i <= NumberOfYears; i++) {
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXYear(short NumberOfYears) {
		DecreaseDateByXYear(*this, NumberOfYears);
	}

	static bool IsEndOfWeek(clsDate Date) {
		short DayIndex = DayOrderInWeek(Date.Year, Date.Month, Date.Day);
		return DayIndex == 6;
	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}
	static bool IsWeekEnd(clsDate Date) {
		short DayIndex = DayOrderInWeek(Date.Year, Date.Month, Date.Day);
		return DayIndex == 6 || DayIndex == 5;
	}
	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date) {
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndWeek(clsDate Date) {
		short currentDay = DayOrderInWeek(Date.Year, Date.Month, Date.Day);
		return 6 - currentDay;
	}

	short DaysUntilEndWeek() {
		return DaysUntilEndWeek(*this);
	}
	static short DaysUntilEndMonth(clsDate Date) {
		clsDate DateMonthEnd;
		DateMonthEnd.Year = Date.Year;
		DateMonthEnd.Month = Date.Month;
		DateMonthEnd.Day = DaysInMonth(Date.Year, Date.Month);
		return GetDifferenceInDays(Date, DateMonthEnd);
	}
	short DaysUntilEndMonth() {
		return DaysUntilEndMonth(*this);
	}
	static short DaysUntilEndYear(clsDate Date) {
		clsDate DateEndYear;
		DateEndYear.Year = Date.Year;
		DateEndYear.Month = 12;
		DateEndYear.Day = 31;
		return GetDifferenceInDays(Date, DateEndYear);
	}
	short DaysUntilEndYear() {
		return DaysUntilEndYear(*this);
	}
	static short ActualVacationsDays(clsDate Date1, clsDate Date2) {
		short Days = 0;
		while (Date1BeforDate2(Date1, Date2)) {

			if (IsWeekEnd(Date1)) {
				Days++;
			}
			Date1 = addOneDay(Date1);
		}
		return Days;
	}
	short ActualVacationsDays(clsDate Date) {
		return ActualVacationsDays(*this, Date);
	}


	static short ActualBusinessDayDays(clsDate Date1, clsDate Date2) {
		short Days = 0;
		while (Date1BeforDate2(Date1, Date2)) {

			if (IsBusinessDay(Date1)) {
				Days++;
			}
			Date1 = addOneDay(Date1);
		}
		return Days;
	}
	short ActualBusinessDayDays(clsDate Date) {
		return ActualBusinessDayDays(*this, Date);
	}

	static clsDate DateVacationEnd(clsDate DateStart, short vacationDays) {
		short Days = 0;
		while (IsWeekEnd(DateStart)) {
			DateStart = addOneDay(DateStart);
			Days++;
		}
		while (Days != vacationDays) {
			DateStart = addOneDay(DateStart);

			if (IsWeekEnd(DateStart)) {
				Days++;
			}
		}
		while (IsWeekEnd(DateStart)) {
			DateStart = addOneDay(DateStart);
			Days++;
		}
		return DateStart;
	}

	clsDate DateVacationEnd(short vacationDays) {
		return DateVacationEnd(*this, vacationDays);
	}
	enum enDateCompare { before = -1, equal = 0, after = 1 };
	static bool Date1AfterDate2(clsDate date1, clsDate date2) {
		return !Date1BeforDate2(date1, date2) && !Date1EqualDate2(date1, date2);
	}
	bool DateAfterDate2(clsDate date) {
		return Date1AfterDate2(*this, date);
	}
	static enDateCompare compareDate(clsDate date1, clsDate date2) {
		if (Date1BeforDate2(date1, date2))return enDateCompare::before;
		if (Date1EqualDate2(date1, date2))return enDateCompare::equal;
		return enDateCompare::after;
	}
	enDateCompare compareDate(clsDate date) {
		return compareDate(*this, date);
	}
};







