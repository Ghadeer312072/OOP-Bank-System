#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsFindCurrencyScreen :
    protected clsScreen
{
private:
  
    static void _PrintCurrency(clsCurrency C) {
        cout << "Currency Found:-)\n";
        cout << "\n\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "Country: " << C.Country << endl;
        cout << "Code: " << C.Code << endl;
        cout << "Name: " << C.Name << endl;
        cout << "Rate(1$): " << C.Rate << endl;

        cout << "\n_____________________________\n\n";
    }
    static void _ShowResult(clsCurrency C) {
        if (!C.ISEmpty()) {
            _PrintCurrency(C);
        }
        else {
            cout << "Currency was not found:-(\n";
        }

    }
    
    static short _ReadFindOption() {
        short answer = 0;
        answer = clsInputValidate::ReadIntNumberBetween(1, 2);
        return answer;
    }
    static void _PerformFindCurrencyMenue(short answer) {
       if(answer==1) {
        
            string code;
            cout << "Please Enter Currency Code: ";
            code = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(code);
            _ShowResult(Currency);
          
       }
       else if (answer == 2) {
           string country;
           cout << "Please Enter Currency Country: ";
           country = clsInputValidate::ReadString();
           clsCurrency Currency = clsCurrency::FindByCountry(country);
           _ShowResult(Currency);
        }
        
        
    }
public:
    static void ShowFindCurrencyMenue() {
        _DrawScreenHeader("Find Cureency Screen");
        cout << "Find By: [1] Code or [2] Country? ";
        _PerformFindCurrencyMenue(_ReadFindOption());
    }
};

