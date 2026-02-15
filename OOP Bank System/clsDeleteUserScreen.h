#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankUser.h"


class clsDeleteUserScreen :
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
    static void ShowDeleteUserScreen() {
        _DrawScreenHeader("Delete User Screen");

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
		cout << "are you sure, you want to Delete this User (y/n)? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y') {
			if (User.Delete()) {
				cout << "you delete user succeesfuly :-)\n";
				_PrintUser(User);

			}
			else {
				cout << "Error User was not deleted.\n";
			}
			
		}
    }
};

