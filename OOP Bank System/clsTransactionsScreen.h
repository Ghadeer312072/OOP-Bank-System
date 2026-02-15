#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"




#include<iostream>

using namespace std;
class clsTransactionsScreen :protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		enDeposit = 1,
		enWithdraw = 2,
		enTotlaBanaces = 3,
		enMainMenue = 4,
	};
	static short _ReadTransactionsMenueOption() {
		cout << "Enter What do you want to do from [1 to 4]? ";
		short option = clsInputValidate::ReadIntNumberBetween(1, 4);
		return option;
	}
	static void _GoBackToTransactionMenue() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";
		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _ShowDepositScreen() {
		//cout << "Deposit Screen Will be here...\n";
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		//cout << "Withdraw Screen Will be here...\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		//cout << "Total Balances Screen Will be here...\n";
		clsTotalBalancesScreen::showTotalBalances();
	}
	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions option) {
		switch (option) {
		case enTransactionsMenueOptions::enDeposit: {
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOptions::enWithdraw: {
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOptions::enTotlaBanaces: {
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOptions::enMainMenue: {
			break;
		}
		}
	}
public:
	static void ShowTransactionsMenue() {
		if (!clsScreen::CheckAccessRight(clsBankUser::enPermissions::eTransaction))return;

		system("cls");
		string Title = "Tranactions Screen";
		_DrawScreenHeader(Title);

		cout << "============================================\n";
		cout << setw(28) << "Transations Menue" << endl;
		cout << "============================================\n";

		cout << "  [1] Deposit.\n";
		cout << "  [2] Withdraw.\n";
		cout << "  [3] Total Balances.\n";
		cout << "  [4] Main Menue.\n";

		cout << "============================================\n";
		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}
};