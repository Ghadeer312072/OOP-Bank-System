#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankUser.h"
#include"Global.h"

using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string SubTitle="") {
		cout << "_________________________________________________________\n\n";
		cout << setw(35) << Title << endl;
		if (SubTitle != "") {
			cout << setw(35) << SubTitle << endl;

		}
		cout << "_________________________________________________________\n\n\n";

	}
	static bool CheckAccessRight(clsBankUser::enPermissions Permission) {
		if (!CurrentUser.CheckAccessPermission(Permission)) {
			cout << "_________________________________________________________\n\n";
			cout << setw(95) << "Access Denied! Contact your Admin." << endl;
			cout << "_________________________________________________________\n\n\n";
			return false;
		}
		return true;
	}
};

