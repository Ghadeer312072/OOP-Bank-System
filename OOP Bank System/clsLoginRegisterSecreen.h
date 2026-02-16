#pragma once
#include "clsScreen.h"
#include "clsBankUser.h"
#include<vector>
class clsLoginRegisterSecreen :
    protected clsScreen
{
private:
	static void _PrintRegisterUserRecordLine(clsBankUser::stLoginRegisterRecord User) {
		cout << left << "|" << setw(25) <<User.date;
		cout << left << "|" << setw(20) << User.userName;
		cout << left << "|" << setw(12) << User.permission << "\n";
	}
public:
    static void ShowLoginRegisterMenue() {
		if (!CheckAccessRight(clsBankUser::enPermissions::enLoginRegister))return;
        vector<clsBankUser::stLoginRegisterRecord> vUsers;
        vUsers = clsBankUser::GetRegisterUsersList();
        string title = "Login Regiser List Screen";
        string subTitle = "(" + to_string(vUsers.size()) + ") Record(s)";
        _DrawScreenHeader(title, subTitle);
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n\n";
		cout << left << "|" << setw(25) << "Date";
		cout << left << "|" << setw(20) << "UserName";
		cout << left << "|" << setw(12) << "Passwprd";
		cout << left << "|" << setw(12) << "Permission";
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
		if (vUsers.size() == 0) {
			cout << setw(25) << "\nNo Users Avaliable In The System!\n";
		}
		else {
			for (clsBankUser::stLoginRegisterRecord& U : vUsers) {
				_PrintRegisterUserRecordLine(U);
			}
		}
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
    }
};

