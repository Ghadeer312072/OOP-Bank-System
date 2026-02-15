#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;
class clsAddNewClientScreen:protected clsScreen
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
	static void ShowAddNewClientScreen() {
		if (!clsScreen::CheckAccessRight(clsBankUser::enPermissions::eAddNewClient))return;

		string Title = "Add New Client Screen";
		_DrawScreenHeader(Title);
		string AccountNumber = "";
		cout << "Please enter account number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "the account number is already exist Please enter account Number again: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		ReadClientInfo(NewClient);
		clsBankClient::enSaveResult SaveResult= NewClient.Save();
		switch (SaveResult)
		{
		case  clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResult::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResult::svFaildAccountNumberIsExist:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}

	}
};

