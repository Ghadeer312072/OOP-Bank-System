#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"







using namespace std;

class clsManageUsersSecreen :
	protected clsScreen
{
private:
	enum enManageUsersMenueOptions {
		eListUsers = 1,
		eAddNewUsers = 2,
		eDeleteUser = 3,
		eUpdateUser = 4,
		eFindUser = 5,
		eMainMenue = 6,
	};
	static short _ReadManageUSersOption() {
		cout << "Choose what do you want to do? [1 to 6]? ";
		short Option = clsInputValidate::ReadIntNumberBetween(1, 6);
		return Option;
	}
	static void GoToManageUsersMenue() {
		cout << setw(60) << "Prease any key to go back to Manage Usere Menue...\n";
		system("pause>0");
		ShowManageUsersMenue();

	}
	static void _ShowListUsersSecreen() {
		//cout << "Show List Users Secreen will be here..." << endl;
		clsListUsersScreen::ShowUsersList();

	}
	static void _ShowAddNewUsersSecreen() {
		//cout << "Show Add New Users Secreen will be here..." << endl;
		clsAddnewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserSecreen() {
		//cout << "Show Delete User Secreen will be here..." << endl;
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserSecreen() {
		//cout << "Show Update User Secreen will be here..." << endl;
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserSecreen() {
		//cout << "Show Find User Secreen will be here..." << endl;
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void PerformManageUsersMenue(enManageUsersMenueOptions option) {
		switch (option) {
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersSecreen();
			GoToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUsers:
		{
			system("cls");
			_ShowAddNewUsersSecreen();
			GoToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserSecreen();
			GoToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserSecreen();
			GoToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserSecreen();
			GoToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			break;
		}
		}
	}
public:
	static void ShowManageUsersMenue() {
		if (!clsScreen::CheckAccessRight(clsBankUser::enPermissions::eManageUsers))return;

		system("cls");
		_DrawScreenHeader("Manage Users Screen");
		cout << "============================================\n";
		cout << setw(28) << "Manage Users Menue" << endl;
		cout << "============================================\n";

		cout << "  [1] Show Users List.\n";
		cout << "  [2] Add New Users.\n";
		cout << "  [3] Delete User.\n";
		cout << "  [4] Update User Info.\n";
		cout << "  [5] Find User.\n";
		cout << "  [6] Main Menue.\n";

		cout << "============================================\n";
		PerformManageUsersMenue((enManageUsersMenueOptions)_ReadManageUSersOption());
	}
};

