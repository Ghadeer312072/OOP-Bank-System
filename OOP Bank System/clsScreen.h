#pragma once
#include<iostream>
#include<iomanip>
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
};

