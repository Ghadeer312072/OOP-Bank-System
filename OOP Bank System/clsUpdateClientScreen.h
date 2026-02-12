#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"



using namespace std;
class clsUpdateClientScreen:protected clsScreen
{
private:
	static void ReadClientInfo(clsBankClient& client) {
		cout << "Please Enter FirstName: ";
		client.FirstName = clsInputValidate::ReadString();
		cout << "Please Enter LastName: ";
		client.LastName = clsInputValidate::ReadString();
		cout << "Please Enter Email: ";
		client.Email = clsInputValidate::ReadString();
		cout << "Please Enter Phone: ";
		client.Phone = clsInputValidate::ReadString();
		cout << "Please Enter PinCode: ";
		client.PinCode = clsInputValidate::ReadString();
		cout << "Please Enter Account Balance: ";
		client.AccountBalance = stof(clsInputValidate::ReadString());
	}
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
	static void showUpdateClientScreen() {
		string Tilte = "Update Client screen";
		_DrawScreenHeader(Tilte);
		string AccountNumber = "";
		cout << "Please Enter account Number? ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Account number is not found, Please enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		char answer = 'n';
		cout << "Are you Shour, you want to update this Client Info (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			ReadClientInfo(Client);
			clsBankClient::enSaveResult saveResult=Client.Save();
			switch (saveResult) {
			case  clsBankClient::enSaveResult::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";

				_PrintClient(Client);
				break;
			}
			case clsBankClient::enSaveResult::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}

			}
			
		}
	}
};

