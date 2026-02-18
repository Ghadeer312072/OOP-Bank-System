#pragma once
#include <string>
using namespace std;

class clsUtil
{

public:
    static string NumberToText(long long number) { 
            	if (number == 0)return "";
            	if (number >= 1 && number <= 19) {
            		string arr_20[20] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight",
            			"nine","ten", "eleven", "twelve", "thirteen","fourteen", "fifteen", "sixteen"
            			,"seventeen", "eighteen", "nineteen"
            		};
            		return arr_20[number];
            	}
            	if (number >= 20 && number <= 99) {
            		string arr_tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
            			"eighty", "ninety"
            		};
            		return arr_tens[number / 10] + " " + NumberToText(number % 10);
            	}
            	if (number >= 100 && number <= 199) {
            		return "One handred " + NumberToText(number % 100);
            	}
            	if (number >= 200 && number <= 999) {
            		return NumberToText(number / 100) + " handreds " + NumberToText(number % 100);
            	}
            	if (number >= 1000 && number <= 1999) {
            		return "One thousand" + NumberToText(number % 1000);
            	}
            	if (number >= 2000 && number <= 999999) {
            		return NumberToText(number / 1000) + " thousands " + NumberToText(number % 1000);
            	}
            	if (number >= 1000000 && number <= 1999999) {
            		return "One million" + NumberToText(number % 1000000);
            	}
            	if (number >= 2000000 && number <= 999999999) {
            		return NumberToText(number / 1000000) + " millions " + NumberToText(number % 1000000);
            	}
            	if (number >= 1000000000 && number <= 1999999999) {
            		return "One billion" + NumberToText(number % 1000000000);
            	}
            	if (number >= 2000000000 && number <= 999999999999) {
            		return NumberToText(number / 1000000000) + " billions " + NumberToText(number % 1000000000);
            	}
            	if (number >= 1000000000000 && number <= 1999999999999) {
            		return "One trillion" + NumberToText(number % 1000000000000);
            	}
            	if (number >= 2000000000000 && number <= 999999999999999) {
            		return NumberToText(number / 1000000000000) + " trillions " + NumberToText(number % 1000000000000);
            	}
            }
    static string EncryptText(string passWord,int key=2) {
        string EncryptedPassword = "";
        for (short i = 0; i < passWord.length(); i++) {
            EncryptedPassword += char((int)passWord[i] +key);
        }
        return EncryptedPassword;
    }
    static string DecryotText(string passWord, int key = 2) {
        string DecryotPassword = "";
        for (short i = 0; i < passWord.length(); i++) {
            DecryotPassword += char((int)passWord[i] - key);
        }
        return DecryotPassword;
    }
};