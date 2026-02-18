#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "Global.h"



class clsTransferScreen :
    protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client) {
        cout << "\n\nClient Card:\n";
        cout << "_____________________________\n";
        cout << "Full Name: " << Client.FullName<<endl;
        cout << "Acc. Numbre: " << Client.AccountNumber << endl;
        cout << "Balance: " << Client.AccountBalance << endl;

        cout << "\n_____________________________\n\n";

    }
    static clsBankClient _AccountToTransferOperation(string message) {
        string AccountNumber = "";
        cout << message;
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account Number is not exist!\n"<< message;
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient ClientToTransferOperation = clsBankClient::Find(AccountNumber);
        return ClientToTransferOperation;
    }
    static float _ReadAmount(clsBankClient ClientToTransferFrom) {
        float Amount = 0;
        cout << "Enter Transfer Amount: ";
        Amount = clsInputValidate::ReadDuobleNumber();
        while (ClientToTransferFrom.AccountBalance < Amount) {
            cout << "Amount Exceeds the available balance, Enter another Amount? ";
            Amount = clsInputValidate::ReadDuobleNumber();
        }
        return Amount;
    }
public:
    static void showTransferScreen() {
        _DrawScreenHeader("Transfer Screen");
        clsBankClient  SourceClient = _AccountToTransferOperation("Please Enter Account Number to Transfer From: ");
        _PrintClient(SourceClient);
        clsBankClient  DestinationClient = _AccountToTransferOperation("Please Enter Account Number to Transfer To: ");
        _PrintClient(DestinationClient);
        float Amount = _ReadAmount(SourceClient);
        char answer = ' ';
        cout << "Are you sure you want to perform this operation?(y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName)) {
                cout << "\nTransfer done succeesfuly:-)\n";
            }
            else {
                cout << "\n Transfer Faild\n";
            }
           
            _PrintClient(SourceClient);
            _PrintClient(DestinationClient);
        }
        
    }
};

