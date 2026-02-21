#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"


class clsCurrencyCalculatorScreen :
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
    static string _GetExistedCurrencyCode(string message) {
        string code = "";
        cout << message;
        code = clsInputValidate::ReadString();
        while (!clsCurrency::ISCurrencyExistByCode(code)) {
            cout << "Invalid code! Please Enter valied Currency Code: ";
            code = clsInputValidate::ReadString();
        }
        return code;
    }
    static void _PrintCalculationsResult(float Amount, clsCurrency Currency1, clsCurrency Currency2) {
        cout << "Convert From:\n";
        _PrintCurrency(Currency1);
        cout << Amount << " " << Currency1.Code << " = " << Currency1.ConvertToUsd(Amount) << " USD\n\n";
        if (Currency2.Code != "USD") {
            cout << "Cnverting from USD to:\nTo:\n\n";
            _PrintCurrency(Currency2);
            cout << Amount << " " << Currency1.Code << " = " << Currency1.ConvertToOtherCurrency(Amount, Currency2) << " " << Currency2.Code << endl;
        }
    }
public:
    static void ShowCurrencyCalculatorScreen() {
        _DrawScreenHeader("Calculor Screen");
        char answer = 'n';

        do {
            string code1 = _GetExistedCurrencyCode("Please Enter Currency1 Code: ");
            string code2 = _GetExistedCurrencyCode("Please Enter Currency2 Code: ");
            clsCurrency Currency1 = clsCurrency::FindByCode(code1);
            clsCurrency Currency2 = clsCurrency::FindByCode(code2);
            cout << "Enter Amount to Exchange: ";
            float Amount = clsInputValidate::ReadDuobleNumber();
            _PrintCalculationsResult(Amount, Currency1, Currency2);

            cout << "Do you want to perform another calculation? y/n? ";
            cin >> answer;
            system("cls");
            _DrawScreenHeader("Calculor Screen");
        } while (answer == 'Y' || answer == 'y');


    }
};


