#pragma once
#include"clsString.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include<vector>
#include<fstream>
#include<string>
#include<iostream>
class clsCurrency
{
private:
	enum enMode{UpdateMode=0, EmptyMode=1};
	enMode _Mode;
	string _Country;
	string _Code;
	string _Name;
	float _Rate;
	static clsCurrency _ConvertCurrencyLineToRecord(string Line) {
		vector<string> vCurrency = clsString::Split(Line,"#//#");
		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}
	static vector<clsCurrency> _LoadCurrenciesFromFile() {
		fstream myfile;
		vector<clsCurrency> vCurrencies;
		myfile.open("Currencies.txt",ios::in);
		if (myfile.is_open()) {
			string line = "";
			
			while (getline(myfile, line)) {
				clsCurrency Currency = _ConvertCurrencyLineToRecord(line);
				vCurrencies.push_back(Currency);
			}

			myfile.close();
		}
		return vCurrencies;
	}
	static clsCurrency _GetEmptyCurrencyOpject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0.0);
	}
	static string _ConvertCurrencyRecordToLine(clsCurrency Currency, string delim = "#//#") {
		string CurrencyLine = "";
		CurrencyLine += Currency.Country + delim;
		CurrencyLine += Currency.Code + delim;
		CurrencyLine += Currency.Name + delim;
		CurrencyLine += to_string(Currency.Rate);

		return CurrencyLine;
	}
	static void _SaveCurrenciesToFile(vector<clsCurrency> vCurrencies) {
		fstream myfile;
		myfile.open("Currencies.txt", ios::out);
		if (myfile.is_open()) {

			for (clsCurrency& C : vCurrencies) {
				string CurrencyLine = _ConvertCurrencyRecordToLine(C);
				myfile << CurrencyLine << endl;
			}

			myfile.close();
		}
	}
	void _Update() {
		vector<clsCurrency> vCurrencies = _LoadCurrenciesFromFile();
		for (clsCurrency& C : vCurrencies) {
			if (C.Code == _Code && C.Country == _Country) {
				C = *this;
			}
		}
		_SaveCurrenciesToFile(vCurrencies);
	}
public:
	string getCountry() {
		return _Country;
	}
	__declspec(property(get = getCountry)) string Country;
	string getCode() {
		return _Code;
	}
	__declspec(property(get = getCode)) string Code;
	string getName() {
		return _Name;
	}
	__declspec(property(get = getName)) string Name;
	float getRate() {
		return _Rate;
	}
	void setRate(float rate) {
		_Rate = rate;
	}
	__declspec(property(get = getRate,put= setRate)) float Rate;
	//////////////////////////////////////////////////////////////////////
	clsCurrency(enMode mode,string country,string code,string name,float rate) {
		_Mode = mode;
		_Country = country;
		_Code = code;
		_Name = name;
		_Rate = rate;
	}
	bool ISEmpty() {
		return _Mode == enMode::EmptyMode;
	}
	
	static vector<clsCurrency> GetCurrenciesList() {
		return _LoadCurrenciesFromFile();
	}
	static clsCurrency FindByCode(string Code) {
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open()) {
			string line = "";

			while (getline(myfile, line)) {
				clsCurrency Currency = _ConvertCurrencyLineToRecord(line);
				if (clsString::LowerAllString(Currency.Code) == clsString::LowerAllString(Code)) {
					myfile.close();
					return Currency;
				}
			}

			myfile.close();
		}
		return _GetEmptyCurrencyOpject();
	}
	static clsCurrency FindByCountry(string Country) {
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open()) {
			string line = "";

			while (getline(myfile, line)) {
				clsCurrency Currency = _ConvertCurrencyLineToRecord(line);
				if (clsString::LowerAllString(Currency.Country) == clsString::LowerAllString(Country)) {
					myfile.close();
					return Currency;
				}
			}

			myfile.close();
		}
		return _GetEmptyCurrencyOpject();
	}
	static bool ISCurrencyExistByCode(string Code) {
		clsCurrency Currency = FindByCode(Code);

		return !(Currency.ISEmpty());
	}
	static bool ISCurrencyExistByCountry(string Country) {
		clsCurrency Currency = FindByCountry(Country);

		return !(Currency.ISEmpty());
	}
	enum enSaveResult{eSucceeded=0,efaildObjectIsEmpty=1};
	enSaveResult Save() {
		switch (_Mode) {
		case enMode::EmptyMode: {
			return enSaveResult::efaildObjectIsEmpty;
		}
		case enMode::UpdateMode: {
			_Update();
			return enSaveResult::eSucceeded;
		}
		}
	}
	float ConvertToUsd(float Amount) {
		return ((float)Amount / _Rate) ;
	}
	float ConvertToOtherCurrency(float Amount,clsCurrency CurrencyTo) {
		float AmountInUSD = ConvertToUsd(Amount);
		if (CurrencyTo.Code != "USD") {
			return AmountInUSD;
		}
		return (float)(AmountInUSD * CurrencyTo.Rate);
	}
};

