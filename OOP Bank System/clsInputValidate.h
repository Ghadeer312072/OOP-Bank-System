#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
class clsInputValidate
{
public:
	static bool ISNumberBetween(short number, short from, short to) {
		return number >= from && number <= to;
	}
	static bool ISNumberBetween(int number, int from, int to) {
		return number >= from && number <= to;
	}
	static bool ISNumberBetween(float number, float from, float to) {
		return number >= from && number <= to;
	}
	static bool ISNumberBetween(double number, double from, double to) {
		return number >= from && number <= to;
	}

	static bool ISDateBetween(clsDate date, clsDate fromDate, clsDate toDate) {
		if (clsDate::compareDate(fromDate, toDate) == clsDate::enDateCompare::after) {
			clsDate::SwapDates(fromDate, toDate);
		}
		return (clsDate::compareDate(date, fromDate) == clsDate::enDateCompare::after || clsDate::compareDate(date, fromDate) == clsDate::enDateCompare::equal) && (clsDate::compareDate(date, toDate) == clsDate::enDateCompare::before || clsDate::compareDate(date, toDate) == clsDate::enDateCompare::equal);
	}
	static int ReadIntNumber(string message = "Invalid Number, Enter again\n") {
		int num = 0;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message;
			cin >> num;
		}
		return num;
	}
	static double ReadDuobleNumber(string message = "Invalid Number, Enter again\n") {
		double num = 0;
		cout << "Please Enter int number: ";
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message;
			cin >> num;
		}
		return num;

	}
	static int ReadIntNumberBetween(int from, int to, string message = "Number is not within range, Enter again:\n") {
		int num = ReadIntNumber(message);
		while (!ISNumberBetween(num, from, to)) {
			cout << message << endl;
			num = ReadIntNumber(message);
		}

		return num;
	}
	static double ReadDoubleNumberBetween(double from, double to, string message = "Number is not within range, Enter again:\n") {
		double num = ReadIntNumber();
		while (!ISNumberBetween(num, from, to)) {
			cout << message << endl;
			num = ReadIntNumber(message);
		}

		return num;
	}
	static bool IsVslidDate(clsDate date) {
		return clsDate::ISValid(date);
	}
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};


