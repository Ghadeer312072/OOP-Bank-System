#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;
class clsDeleteClientScreen:protected clsScreen
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
	static void ShowDeleteClientScreen() {
		string Title = "Delete Client Screen";
		_DrawScreenHeader(Title);
		string AccountNumber = "";
		cout << "Please enter account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client is not Exist, Please enter account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		char answer;
		cout << "Are you sure,you want to delete this account (y/n)? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			if (Client.Delete()) {
				cout << "Client Deleted successfully :-)\n" << endl;
				_PrintClient(Client);

			}
			else {
				cout << "Error Client was not deleted.\n";
			}
		}

		
	}
};

