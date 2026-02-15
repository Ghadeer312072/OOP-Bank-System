#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankUser.h"


class clsAddnewUserScreen :
	protected clsScreen
{
private:
	static void ReadUserInfo(clsBankUser& user) {
		cout << "Please Enter FirstName: ";
		user.FirstName = clsInputValidate::ReadString();
		cout << "Please Enter LastName: ";
		user.LastName = clsInputValidate::ReadString();
		cout << "Please Enter Email: ";
		user.Email = clsInputValidate::ReadString();
		cout << "Please Enter Phone: ";
		user.Phone = clsInputValidate::ReadString();
		cout << "Please Enter Password: ";
		user.Password = clsInputValidate::ReadString();
		cout << "Please Enter Permission: ";
		user.Permission = _ReadPermissionToSet();
	}
	static void _PrintUser(clsBankUser user) {
		cout << "\n User Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << user.FirstName;
		cout << "\nLastName    : " << user.LastName;
		cout << "\nFull Name   : " << user.getFullName();
		cout << "\nEmail       : " << user.Email;
		cout << "\nPhone       : " << user.Phone;
		cout << "\nAcc. Number : " << user.UserName;
		cout << "\nPassword    : " << user.Password;
		cout << "\nPermission     : " << user.Permission;
		cout << "\n___________________\n";
	}
	static int _ReadPermissionToSet() {
		int Permission = 0;
		char answer = ' ';
		cout << "give Full Permissions (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')return -1;
		cout << "\nDo you want to give access to: \n";
		cout << "Show Client List? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::eClientsList;
		}
		cout << "Show Add New Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::eAddNewClient;
		}
		cout << "Show Delete Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::eDeleteClient;
		}
		cout << "Show Update Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::eUpdateClient;
		}
		cout << "Show Find Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::eFindClient;
		}
		cout << "show Transaction? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::eTransaction;
		}
		cout << "Show Manage Users? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::eManageUsers;
		}
		return Permission;
	}
public:
	static void ShowAddNewUserScreen() {
		_DrawScreenHeader("Add New User Screen");
		string userName;
		cout << "Please enter UserName? ";
		userName = clsInputValidate::ReadString();
		while (clsBankUser::IsUserExist(userName)) {
			cout << "UserName already exist! Please enter UserName? ";
			userName = clsInputValidate::ReadString();
		}
		clsBankUser newUser = clsBankUser::_GetAddNewObject(userName);
		ReadUserInfo(newUser);
		char answer = ' ';
		cout << "Are you shur, you want to add this client (y/n)? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			clsBankUser::enSaveResult saveResult;
			saveResult = newUser.Save();
			switch (saveResult) {
			case clsBankUser::enSaveResult::svSucceeded:
			{
				cout << "\nAccount Addeded Successfully :-)\n";
				_PrintUser(newUser);
				break;
			}
			case clsBankUser::enSaveResult::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}
			case clsBankUser::enSaveResult::svFaildUserExists:
			{
				cout << "\nError account was not saved because userName is used!\n";
				break;

			}
			}

		};

	}
};