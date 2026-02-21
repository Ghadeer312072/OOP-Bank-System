#pragma once
#include<iostream>
#include<vector>
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;

class clsClientsListScreen:protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient C) {
		cout << left << "|" << setw(19) << C.AccountNumber;
		cout << left << "|" << setw(20) << C.FullName;
		cout << left << "|" << setw(12) << C.Phone;
		cout << left << "|" << setw(20) << C.Email;
		cout << left << "|" << setw(12) << C.PinCode;
		cout << left << "|" << setw(12) << C.AccountBalance << "\n";
	}
public:
	static void ShowClientsList() {
		if (!clsScreen::CheckAccessRight(clsBankUser::enPermissions::eClientsList))return;
		vector<clsBankClient> Clients = clsBankClient::GetClientsList();
		string Title = "Clients List Screen";
		string SubTitle ="("+ to_string(Clients.size()) + ") Client(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n\n";
		cout << left << "|" << setw(19) << "Account Number";
		cout << left << "|" << setw(20) << "Client Name";
		cout << left << "|" << setw(12) << "Phone";
		cout << left << "|" << setw(20) << "Email";
		cout << left << "|" << setw(12) << "Pin Code";
		cout << left << "|" << setw(12) << "Balance";
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
		if (Clients.size() == 0) {
			cout << setw(25) << "\nNo Clients Avaliable In The System!\n";
		}
		else {
			for (clsBankClient& C : Clients) {
				_PrintClientRecordLine(C);
			}
		}
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
	}
};

