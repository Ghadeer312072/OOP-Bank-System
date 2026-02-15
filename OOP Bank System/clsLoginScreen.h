#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankUser.h"
#include "clsMainScreen.h"
#include"Global.h"

class clsLoginScreen :
    protected clsScreen
{
private:
    static void _Login() {
        string userName = " ";
        string password = " ";
        bool LoginFaild = false;
        do {
            if (LoginFaild) {
                cout << "invalid userName/password!\n";
            }

            cout << "Please Entre userName: ";
            userName = clsInputValidate::ReadString();
            cout << "Please Entre Password: ";
            password = clsInputValidate::ReadString();
           
           CurrentUser = clsBankUser::Find(userName, password);
           LoginFaild = CurrentUser.isEmpty();
        } while (LoginFaild);
        
        clsMainScreen::ShowMainMenueScreen();
    }
public:
    static void ShowLoginScreen() {
        system("cls");
        _DrawScreenHeader("Login Screen");
        _Login();
    }
};

