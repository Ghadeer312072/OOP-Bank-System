#pragma once
#include "clsScreen.h"
#include "clsBankUser.h"
#include<iomanip>
#include<iostream>
using namespace std;
class clsListUsersScreen :
    protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsBankUser User) {
		cout << left << "|" << setw(19) << User.UserName;
		cout << left << "|" << setw(20) << User.FullName;
		cout << left << "|" << setw(12) << User.Phone;
		cout << left << "|" << setw(20) << User.Email;
		cout << left << "|" << setw(12) << User.Password;
		cout << left << "|" << setw(12) << User.Permission << "\n";
    }
public:
	static void ShowUsersList() {
		vector<clsBankUser> Users = clsBankUser::GetUsersList();
		string Title = "Users List Screen";
		string SubTitle = "(" + to_string(Users.size()) + ") User(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n\n";
		cout << left << "|" << setw(19) << "UserName";
		cout << left << "|" << setw(20) << "Client Name";
		cout << left << "|" << setw(12) << "Phone";
		cout << left << "|" << setw(20) << "Email";
		cout << left << "|" << setw(12) << "Passwprd";
		cout << left << "|" << setw(12) << "Permission";
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
		if (Users.size() == 0) {
			cout << setw(25) << "\nNo Users Avaliable In The System!\n";
		}
		else {
			for (clsBankUser& U : Users) {
				_PrintUserRecordLine(U);
			}
		}
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
	}
};

