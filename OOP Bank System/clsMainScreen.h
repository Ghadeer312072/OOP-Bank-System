#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersSecreen.h"
#include"clsLoginRegisterSecreen.h"


#include"Global.h"




using namespace std;
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions {
		eClientsList =1,
		eAddNewClient=2,
		eDeleteClient=3,
		eUpdateClientInfo=4,
		eFindClient=5,
		eTransactions=6,
		eManageUsers=7,
		eLoginRegister=8,
		eLogout=9
	};
	static void _GoToMainMenue() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenueScreen();
	}
	static void _ShowAllClientsScreen() {
		clsClientsListScreen::ShowClientsList();
	}
	static void _ShowAddNewClientScreen() {
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientScreen() {
		//cout << "Delete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientInfoScreen() {
		//cout << "Update Clien tInfo Screen Will be here...\n";
		clsUpdateClientScreen::showUpdateClientScreen();
	}
	static void _ShowFindClientScreen() {
		//cout << "Find Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsScreen() {
		//cout << "Transactions Screen Will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenue();
	}
	static void _ShowManageUsersScreen() {
		//cout << "Manage Users Screen Will be here...\n";
		clsManageUsersSecreen::ShowManageUsersMenue();
	}
	static void _ShowLoginRegisterScreen() {
		//cout << "Login Register Screen Will be here...\n";
		clsLoginRegisterSecreen::ShowLoginRegisterMenue();
	}
	static void _Logout() {
	 CurrentUser = clsBankUser::Find("", "");

	}
	static void _PerformMainMenueOptions(enMainMenueOptions option) {
		switch (option) {
		case enMainMenueOptions::eClientsList: {
			system("cls");
			_ShowAllClientsScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient: {
			system("cls");
			_ShowAddNewClientScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient: {
			system("cls");
			_ShowDeleteClientScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClientInfo: {
			system("cls");
			_ShowUpdateClientInfoScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient: {
			system("cls");
			_ShowFindClientScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eTransactions: {
			system("cls");
			_ShowTransactionsScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers: {
			system("cls");
			_ShowManageUsersScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister: {
			system("cls");
			_ShowLoginRegisterScreen();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eLogout: {
			system("cls");
			_Logout();
			break;
		}
		}
	}
	static short _ReadMainMenueOption() {
		cout << "Choose what do you want to do? [1 to 9]? ";
		short option= clsInputValidate::ReadIntNumberBetween(1, 9,"Please Enter Number Between 1 to 8");
		return option;
	}
public:
	static void ShowMainMenueScreen() {
		system("cls");
		_DrawScreenHeader("Main Screen");
		cout << "============================================\n";
			cout << setw(28) << "Main Menue" << endl;
		cout << "============================================\n";

		cout <<"  [1] Show Clients List.\n";
		cout << "  [2] Add New Client.\n";
		cout << "  [3] Delete Client.\n";
		cout << "  [4] Update Client Info.\n";
		cout << "  [5] Find Client.\n";
		cout << "  [6] Transactions.\n";
		cout << "  [7] Manage Users.\n";
		cout << "  [8] Login Register.\n";
		cout << "  [9] Logout.\n";
		cout << "============================================\n";
		_PerformMainMenueOptions((enMainMenueOptions)_ReadMainMenueOption());
	}

};

