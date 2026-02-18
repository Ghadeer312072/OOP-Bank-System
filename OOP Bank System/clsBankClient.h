#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include"Global.h"
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
	string _PrepareTransferRecord(float Amount, clsBankClient DestinationClient, string UserName, string delim = "#//#") {
		string TransferDataline = "";
		TransferDataline += clsDate::GetSystemDateTimeString() + delim;
		TransferDataline += _AccountNumber + delim;
		TransferDataline += DestinationClient.AccountNumber + delim;
		TransferDataline += to_string(Amount) + delim;
		TransferDataline += to_string(AccountBalance) + delim;
		TransferDataline += to_string(DestinationClient.AccountBalance) + delim;
		TransferDataline += CurrentUser.UserName;




		return TransferDataline;
	}
	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient,string UserName) {
		fstream myfile;
		string stDataLine = _PrepareTransferRecord(Amount, DestinationClient, UserName);
		myfile.open("TransferLog.txt", ios::out | ios::app);
		if (myfile.is_open()) {
			myfile <<stDataLine << endl;
			myfile.close();
		}
	}
	struct stTransferLogRecord;
	static stTransferLogRecord _ConviretTransferLogLineToRecord(string line) {
		vector<string> vOPerations = clsString::Split(line,"#//#");
		stTransferLogRecord TrancgerOperation;
		TrancgerOperation.Date_Time = vOPerations[0];
		TrancgerOperation.SourceAcc = vOPerations[1];
		TrancgerOperation.distinationAcc = vOPerations[2];
		TrancgerOperation.Amount = stod(vOPerations[3]);
		TrancgerOperation.SourceBalance = stod(vOPerations[4]);
		TrancgerOperation.DistinationBalance = stod(vOPerations[5]);
		TrancgerOperation.UserName = vOPerations[6];

		return TrancgerOperation;
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
	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName) {
		if (Amount > _AccountBalance)return false;
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}
	struct stTransferLogRecord {
		string Date_Time;
		string SourceAcc;
		string distinationAcc;
		float Amount;
		float SourceBalance;
		float DistinationBalance;
		string UserName;
	};
	static vector<stTransferLogRecord> GetTransferLogList() {
		vector<stTransferLogRecord> vTransferOperations;
		fstream myFile;
		myFile.open("TransferLog.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			stTransferLogRecord TrancgerOperation;
			while (getline(myFile, line)) {
				 TrancgerOperation = _ConviretTransferLogLineToRecord(line);
				 vTransferOperations.push_back(TrancgerOperation);
			}
			myFile.close();
		}
		return vTransferOperations;
	}

	
};

