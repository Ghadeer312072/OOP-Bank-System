#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include<iostream>

using namespace std;
class clsWithdrawScreen :
    protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.getFullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}
public:
	static void ShowWithdrawScreen() {
		_DrawScreenHeader("Withdraw Screeen");
		string AccountNumber = "";
		cout << "Please enter an account number to Withdraw? ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client with [" << AccountNumber << "] is dose not Exist.\nPlease enter AccountNumber: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double amount = 0;
		cout << "Please Enter an amount to Deposit: ";
		amount = clsInputValidate::ReadDuobleNumber();
		while (amount > Client.AccountBalance) {
			cout << "the balance is less than your withdraw amount!!\n";
			cout << "Please Enter an amount to Deposit: ";
			amount = clsInputValidate::ReadDuobleNumber();
		}
		char answer = ' ';
		cout << "Are you Shour you want to perform this transaction (y/n)? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			if (Client.Withdraw(amount)) {
				cout << "the Deposit Withdraw is done Succeesfuly. :-)\n";
				cout << "your Balance after Withdraw is " << Client.AccountBalance << endl;
			}
			else {
				cout << "Amount to withdraw is: " << Client.AccountBalance+amount << endl;
				cout << "your balance is: " << Client.AccountBalance << endl;
			}
		}
		else {
			cout << "Operation was cancelled.\n";
		}

	}
};


