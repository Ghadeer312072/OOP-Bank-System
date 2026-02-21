#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"


#include<iostream>
#include<iomanip>


using namespace std;
class clsCurrencyMainScreen :
    protected clsScreen
{
private:
    enum enCurrencyScreenOption {
        ListCurrencies = 1,
        FindCurrency = 2,
        UpdateCurrency = 3,
        CurrencyCalculator = 4,
        MainMenue = 5,

    };
    static void _GoBackToCurrencyScreen() {
        cout << "\n\n";
        cout << setw(60) << "Press any key to back to Currency Screen:-)";
        system("pause>0");
        ShowCurrencyMainMenue();
    }
    static short _ReadOption() {
        short option;
        cout << "Enter Option Between [1 to 5]? ";
        option = clsInputValidate::ReadIntNumberBetween(1, 5);
        return option;
    }
    static void _ShowListCurrenciesScreen() {
        //cout << "List Currencies Screen will be here...\n";
        clsListCurrenciesScreen::ShowListCurrenciesMenue();
    }
    static void _ShowFindCurrencyScreen() {
        //cout << "Find Currency Screen will be here...\n";
        clsFindCurrencyScreen::ShowFindCurrencyMenue();

    }
    static void _ShowUpdateCurrencyScreen() {
        //cout << "List Update Currency Screen will be here...\n";
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();

    }
    static void _ShowCurrencyCalculatorScreen() {
        //cout << "List Currency Calculator Screen will be here...\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }
    static void _ShowMainMenueScreen() {
        cout << "Press any key to show Main Menue! \n";
        system("pause>0");
    }
    static void _PerformCurrencyMainScreen(enCurrencyScreenOption Option) {
        switch (Option) {
        case enCurrencyScreenOption::ListCurrencies: {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyScreenOption::FindCurrency: {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyScreenOption::UpdateCurrency: {
            system("cls");
            _ShowUpdateCurrencyScreen();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyScreenOption::CurrencyCalculator: {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyScreen();
            break;
        }
        case enCurrencyScreenOption::MainMenue: {
            system("cls");
            _ShowMainMenueScreen();
            break;
        }
        }
    }
public:
    static void ShowCurrencyMainMenue() {
        if (!CheckAccessRight(clsBankUser::enPermissions::enCurrencyExchange))return;
        system("cls");
        _DrawScreenHeader("Currency Exchange Main Screen");
        cout << "==================================================================\n";
        cout << setw(35) << "Currency Exchange Menue\n";
        cout << "==================================================================\n";
        cout << "  [1] List Currencies.\n";
        cout << "  [2] Find Currency.\n";
        cout << "  [3] Update Currency.\n";
        cout << "  [4] Currency Calculator.\n";
        cout << "  [5] Main Menue.\n";
        cout << "==================================================================\n";

        _PerformCurrencyMainScreen((enCurrencyScreenOption)_ReadOption());
    }
};


