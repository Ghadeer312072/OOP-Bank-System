#pragma once
#include "clsScreen.h"
class clsTransferLogScreen :
    protected clsScreen
{
private:
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord Transfer) {
		cout << left << "|" << setw(25) << Transfer.Date_Time;
		cout << left << "|" << setw(20) << Transfer.SourceAcc;
		cout << left << "|" << setw(20) << Transfer.distinationAcc;
		cout << left << "|" << setw(12) << Transfer.Amount;
		cout << left << "|" << setw(12) << Transfer.SourceBalance;
		cout << left << "|" << setw(12) << Transfer.DistinationBalance;
		cout << left << "|" << setw(12) << Transfer.UserName<< endl;
	}
public:
    static void showTransferLogScreen() {
		vector<clsBankClient::stTransferLogRecord> vTransferOperations;
		vTransferOperations = clsBankClient::GetTransferLogList();
		string title = "Transfer log List Screen";
		string subTitle = "(" + to_string(vTransferOperations.size()) + ") Record(s)";
		_DrawScreenHeader(title, subTitle);
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n\n";
		cout << left << "|" << setw(25) << "Date/Time";
		cout << left << "|" << setw(20) << "SourceAccount";
		cout << left << "|" << setw(20) << "DistinationAccount";
		cout << left << "|" << setw(12) << "Amount";
		cout << left << "|" << setw(12) << "S.Balance";
		cout << left << "|" << setw(12) << "D.Balance";
		cout << left << "|" << setw(12) << "User";



		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
		if (vTransferOperations.size() == 0) {
			cout << setw(25) << "\nNo Transfer operations In The System!\n";
		}
		else {
			for (clsBankClient::stTransferLogRecord& U : vTransferOperations) {
				_PrintTransferLogRecordLine(U);
			}
		}
		cout << "\n________________________________________________________________";
		cout << "_________________________________________\n";
    }
};

