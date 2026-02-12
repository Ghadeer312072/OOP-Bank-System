#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include<vector>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
class clsBankClient:public clsPerson
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1,AddNew=2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkeForDeleted = false;
	bool isEmpty() {
		return _Mode == enMode::EmptyMode;
	}
	static clsBankClient _ConviretLineToClientObject(string line) {
		vector<string> vClient = clsString::Split(line, "#//#");
		return clsBankClient(enMode::UpdateMode,vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));

	}
	static clsBankClient _GetEmptyObject() {
		return clsBankClient(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);
	}
	string _ConvertObjectToLine(clsBankClient client,string delim="#//#") {
		string ClientLine = "";
		ClientLine += client.FirstName + delim;
		ClientLine += client.LastName + delim;
		ClientLine += client.Email + delim;
		ClientLine += client.Phone + delim;
		ClientLine += client.AccountNumber + delim;
		ClientLine += client.PinCode + delim;
		ClientLine += to_string(client.AccountBalance);
		return ClientLine;
	}
	static vector<clsBankClient> _LoadClientsFromFile() {
		vector<clsBankClient> vClients;
		fstream myFile;
		myFile.open("Clients.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankClient client = _ConviretLineToClientObject(line);
				vClients.push_back(client);
			}
			myFile.close();
		}
		return vClients;
	}
	void _SaveClientToFile(vector<clsBankClient> vClients) {
		fstream myFile;
		myFile.open("Clients.txt", ios::out);
		string Dataline;

		if (myFile.is_open()) {
			for (clsBankClient& C : vClients) {
				if (C._MarkeForDeleted == false) {
					Dataline = _ConvertObjectToLine(C);
					myFile << Dataline << "\n";
				}
			}
			myFile.close();
		}
	}
	void _Update() {
		vector<clsBankClient> vClients;
		vClients = _LoadClientsFromFile();
		for (clsBankClient& C : vClients) {
			if (C.AccountNumber == getAccountNumber()) {
				C = *this;
				break;
			}
		}
		_SaveClientToFile(vClients);
	}
	void AddDataLineToFile(string ClientLine) {
		fstream myFile;
		myFile.open("Clients.txt", ios::out|ios::app);
		if (myFile.is_open()) {
			myFile << ClientLine << "\n";
			myFile.close();
		}
	}
	void _AddNew() {
		AddDataLineToFile(_ConvertObjectToLine(*this));
	}
public:
	
	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance) :
		clsPerson(firstName,lastName,email,phone) {
		_Mode=mode;
		 _AccountNumber= accountNumber;
		 _PinCode= pinCode;
		 _AccountBalance= accountBalance;
	}
	string getAccountNumber() {
		return _AccountNumber;
	}
	__declspec(property(get= getAccountNumber)) string AccountNumber;
	////////////////
	void setPinCode(string pinCode) {
		 _PinCode=pinCode;
	}
	string getPinCode() {
		return _PinCode;
	}
	__declspec(property(get = getPinCode,put= setPinCode)) string PinCode;
	////////////////
	void setAccountBalance(float accountNumber) {
		_AccountBalance = accountNumber;
	}
	float getAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;
	/////////////////

	static clsBankClient Find(string accountNamber) {
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				clsBankClient client = _ConviretLineToClientObject(line);
				if (client.getAccountNumber() == accountNamber) {
					myfile.close();
					return client;
				}

			}
			myfile.close();
		}
		return _GetEmptyObject();
	}
	static clsBankClient Find(string accountNamber,string pinCode) {
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				clsBankClient client = _ConviretLineToClientObject(line);
				if (client.getAccountNumber() == accountNamber&&client.getPinCode()== pinCode) {
					myfile.close();
					return client;
				}

			}
			myfile.close();
		}
		return _GetEmptyObject();
	}
	///////////////
	
	static bool IsClientExist(string accountNumber) {
		clsBankClient client = clsBankClient::Find(accountNumber);

		return !client.isEmpty();
	}
	static clsBankClient GetAddNewClientObject(string accountNumber) {
		return clsBankClient(enMode::AddNew, " ", " ", " ", " ", accountNumber, " ", 0);
	}
	static enum enSaveResult {svFaildEmptyObject=0,svSucceeded=1,svFaildAccountNumberIsExist=2};
	enSaveResult Save() {
		switch (_Mode) {
		case enMode::EmptyMode: {
			return enSaveResult::svFaildEmptyObject;
			break;
		}
		case enMode::UpdateMode: {
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case enMode::AddNew: {
			if (IsClientExist(_AccountNumber)) {
				return svFaildAccountNumberIsExist;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		}
	}
	bool Delete() {
		vector <clsBankClient> Clients;
		Clients = _LoadClientsFromFile();
		for (clsBankClient& C : Clients) {
			if (C.AccountNumber == getAccountNumber()) {
				C._MarkeForDeleted = true;
				break;
			}
		}
		_SaveClientToFile(Clients);
		*this = _GetEmptyObject();
		return true;
	}
	static vector<clsBankClient> GetClientsList() {
		return _LoadClientsFromFile();
	}
	static float GetTotalBalances() {
		vector<clsBankClient> Clients = _LoadClientsFromFile();
		float Balances = 0;
		for (clsBankClient& C : Clients) {
			Balances += C.AccountBalance;
		}
		return Balances;
	}
	void Deposit(double Amount) {
		AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount) {
		if (Amount > AccountBalance) {
			return false;
		}
		else {
			AccountBalance -= Amount;
			Save();
		}
		
	}
};

