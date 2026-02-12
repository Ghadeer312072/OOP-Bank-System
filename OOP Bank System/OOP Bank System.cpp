#include <iostream>
#include<iomanip>
#include"clsUtil.h"
#include"clsBankClient.h"
#include"clsMainScreen.h"
using namespace std; 

void ShowClientsList() {
	vector<clsBankClient> Clients = clsBankClient::GetClientsList();
	cout <<setw(45)<< "Client List ("<< Clients.size()<<") Client(s).";
	cout << "\n________________________________________________________________";
	cout << "_________________________________________\n\n";
	cout << left << "|" << setw(19) <<"Account Number";
	cout << left << "|" << setw(20) << "Client Name";
	cout << left << "|" << setw(12) << "Phone";
	cout << left << "|" << setw(20) << "Email";
	cout << left << "|" << setw(12) << "Pin Code";
	cout << left << "|" << setw(12) << "Balance";
	cout << "\n________________________________________________________________";
	cout << "_________________________________________\n";
	if (Clients.size()==0) {
		cout << setw(25) << "\nNo Clients Avaliable In The System!\n";
	}
	else {
		for (clsBankClient& C : Clients) {
			cout << left << "|" <<setw(19) <<C.AccountNumber ;
			cout << left << "|" << setw(20) <<C.FullName ;
			cout << left << "|" << setw(12) <<C.Phone;
			cout << left << "|" << setw(20) <<C.Email ;
			cout << left << "|" << setw(12) <<C.PinCode;
			cout << left << "|" << setw(12) <<C.AccountBalance <<"\n";
			
		}
	}
	cout << "\n________________________________________________________________";
	cout << "_________________________________________\n";
}
void ShowTotalBalances() {
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
			cout << left << "|" << setw(19) << C.AccountNumber;
			cout << left << "|" << setw(30) << C.FullName;
			cout << left << "|" << setw(12) << C.AccountBalance << "\n";

		}
	}
	cout << "\n________________________________________________________________";
	cout << "_________________________________________\n";
	float Balances = clsBankClient::GetTotalBalances();
	cout << "Total Balances = " << Balances << endl;
	cout << "(" << clsUtil::NumberToText(Balances)<<")\n";
}
int main()
{
	
	//ShowClientsList();
	//ShowTotalBalances();
	clsMainScreen::ShowMainMenueScreen();
	
}
