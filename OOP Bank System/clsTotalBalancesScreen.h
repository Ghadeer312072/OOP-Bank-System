#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"

class clsTotalBalancesScreen :
    protected clsScreen
{
private:
	static void PrintClientRecordLine(clsBankClient Client) {
		cout << left << "|" << setw(19) << Client.AccountNumber;
		cout << left << "|" << setw(30) << Client.FullName;
		cout << left << "|" << setw(12) << Client.AccountBalance << "\n";
	}
public:
    static void showTotalBalances() {
		vector<clsBankClient> Clients = clsBankClient::GetClientsList();
		cout << setw(45) << "Balances list (" << Clients.size() << ") Client(s).";
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n\n";
		cout << left << "|" << setw(19) << "Account Number";
		cout << left << "|" << setw(30) << "Client Name";
		cout << left << "|" << setw(12) << "Balance";
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
		if (Clients.size() == 0) {
			cout << setw(25) << "\nNo Clients Avaliable In The System!\n";
		}
		else {
			for (clsBankClient& C : Clients) {
				PrintClientRecordLine(C);
			}
		}
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
		float Balances = clsBankClient::GetTotalBalances();
		cout << "Total Balances = " << Balances << endl;
		cout << "(" << clsUtil::NumberToText(Balances) << ")\n";
    }
};

