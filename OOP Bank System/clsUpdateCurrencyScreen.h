#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsUpdateCurrencyScreen :
    protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency C) {

        cout << "\n\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "Country: " << C.Country << endl;
        cout << "Code: " << C.Code << endl;
        cout << "Name: " << C.Name << endl;
        cout << "Rate(1$): " << C.Rate << endl;

        cout << "\n_____________________________\n\n";
    }
    static void _ReadCurrrencyRate(clsCurrency& Currency) {
        cout << "Update Currency Rate:\n";
        cout << "_______________________\n";
        cout << "Please Enter Currency Rate: ";
        Currency.Rate = clsInputValidate::ReadDuobleNumber();
    }
    static string _GetExistedCurrencyCode() {
        string code = "";
        cout << "Please Enter Currency Code: ";
        code = clsInputValidate::ReadString();
        while (!clsCurrency::ISCurrencyExistByCode(code)) {
            cout << "Invalid code! Please Enter Currency Code: ";
            code = clsInputValidate::ReadString();
        }
        return code;
    }
public:
    static void ShowUpdateCurrencyScreen() {
        _DrawScreenHeader("Update Currency Screen");
        string code = _GetExistedCurrencyCode();
        clsCurrency Currency = clsCurrency::FindByCode(code);
        _PrintCurrency(Currency);
        char answer = ' ';
        cout << "Are you sure you want to update the rate of this Currency y/n? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y') {
            _ReadCurrrencyRate(Currency);
            Currency.Save();
            _PrintCurrency(Currency);
        }
    }
};

