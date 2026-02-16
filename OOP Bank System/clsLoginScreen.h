#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankUser.h"
#include "clsMainScreen.h"

class clsLoginScreen :
    protected clsScreen
{
private:
    static bool _Login() {
        string userName = " ";
        string password = " ";
        bool LoginFaild = false;
        short TrailLoginFaild = 3;

        do {
            
            if (LoginFaild) {
                TrailLoginFaild--;
                cout << "invalid userName/password!\n";
                cout << "you have " + to_string(TrailLoginFaild) + " trail(s) to Login.\n";
            }
            if (TrailLoginFaild == 0) {
                cout << "you are locked after three trials." << endl;
                return false;
            }
            cout << "Please Entre userName: ";
            userName = clsInputValidate::ReadString();
            cout << "Please Entre Password: ";
            password = clsInputValidate::ReadString();
           
           CurrentUser = clsBankUser::Find(userName, password);
           LoginFaild = CurrentUser.isEmpty();
           
        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenueScreen();
        return true;
    }
public:
    static bool ShowLoginScreen() {
        system("cls");
        _DrawScreenHeader("Login Screen");
        return _Login();
    }
};

