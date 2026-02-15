#pragma once
#include "clsScreen.h"
#include "clsBankUser.h"

class clsFindUserScreen :
    protected clsScreen
{
private:
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
public:
	static void ShowFindUserScreen() {
		_DrawScreenHeader("Find User Screen");

		string userName = "";
		cout << "Please Enter userName: ";
		userName = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(userName)) {
			cout << "userName is not Exist! Please Enter userName: ";
			userName = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::Find(userName);
		_PrintUser(User);
	}
};

