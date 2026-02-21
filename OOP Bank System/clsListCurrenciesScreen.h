#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include<vector>
#include<iomanip>
#include<iostream>
using namespace std;

class clsListCurrenciesScreen :
    protected clsScreen
{
private:
    static void _PrintCurencyInfo(clsCurrency C) {
        cout << left << setw(40) <<C.Country;
        cout << left << setw(12) <<C.Code;
        cout << left << setw(50) << C.Name;
        cout << left << setw(12) << C.Rate<<endl;
    }
public:
    static void ShowListCurrenciesMenue() {
        vector< clsCurrency> vCurrencies;
        vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "Currencies List Screen";
        string SubTitle = "(" + to_string(vCurrencies.size()) + ") Currency.";
        _DrawScreenHeader(Title, SubTitle);
        if (vCurrencies.size() == 0) {
            cout << setw(60) << "no Currensy avaliable in the system! ";
        }
        else {
            cout << "________________________________________________________________________________________________________________\n";
            cout << left << setw(40) << "|Country";
            cout << left << setw(12) << "|Code";
            cout << left << setw(50) << "|Name";
            cout << left << setw(12) << "|Rate/(1$)\n";
            cout << "________________________________________________________________________________________________________________\n";
            for (clsCurrency& C : vCurrencies) {
                _PrintCurencyInfo(C);
            }
            cout << "________________________________________________________________________________________________________________\n";

        }
    }
};

