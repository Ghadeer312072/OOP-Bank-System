#include <iostream>
#include<iomanip>
#include"clsUtil.h"
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsBankUser.h"
#include"clsLoginScreen.h"

using namespace std; 

int main()
{
	while (true) {
		
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}
	}
	
	
}
