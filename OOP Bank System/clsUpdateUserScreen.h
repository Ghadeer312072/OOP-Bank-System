#pragma once
#include "clsScreen.h"
#include "clsBankUser.h"

class clsUpdateUserScreen :
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
		cout << "Show Login Register? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::enLoginRegister;
		}
		cout << "Show Currency Exchange? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			Permission += clsBankUser::enPermissions::enCurrencyExchange;
		}
		return Permission;
	}
public:
    static void ShowUpdateUserScreen() {
		_DrawScreenHeader("Update User Screen");

		string userName = "";
		cout << "Please Enter userName: ";
		userName = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(userName)) {
			cout << "userName is not Exist! Please Enter userName: ";
			userName = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::Find(userName);
		_PrintUser(User);
		char answer = ' ';
		cout << "are you sure, you want to Update this User (y/n)? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			ReadUserInfo(User);
			clsBankUser::enSaveResult saveResult;
			saveResult = User.Save();
			switch (saveResult) {
			case clsBankUser::enSaveResult::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";
				_PrintUser(User);
				break;
			}
			case clsBankUser::enSaveResult::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}
			}
		}
    }
};

