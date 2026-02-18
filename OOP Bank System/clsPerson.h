#pragma once
#include"InterfaceCommunication.h"
#include<iostream>
using namespace std;
class clsPerson:public InterfaceCommunication
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	clsPerson(){}
	clsPerson(string firstName,string lastName, string email, string phone) {
		 _FirstName=firstName;
		 _LastName=lastName;
		 _Email=email;
		 _Phone=phone;
	}
	void setFirstName(string firstName) {
		_FirstName = firstName;
	}
	string getFirstName() {
		return _FirstName;
	}
	__declspec(property(get= getFirstName,put= setFirstName)) string FirstName;
	/////////////
	void setLastName(string lastName) {
		_LastName = lastName;
	}
	string getLastName() {
		return _LastName;
	}
	__declspec(property(get = getLastName, put = setLastName)) string LastName;
	/////////////////
	void setEmail(string email) {
		_Email = email;
	}
	string getEmail() {
		return _Email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string Email;
	//////////////////
	void setPhone(string phone) {
		_Phone = phone;
	}
	string getPhone() {
		return _Phone;
	}
	__declspec(property(get = getPhone, put = setPhone)) string Phone;
	///////////////////
	string getFullName() {
		return FirstName + " " + LastName;
	}
	__declspec(property(get = getFullName)) string FullName;
	///////////////abstract class methods implementation
	void SendEmail(string Title, string Body) {};
	void SendFax(string Title, string Body) {};
	void SendSMS(string Title, string Body) {};
	/*void Print() {
		cout << "\n Info";
		cout << "\n_____________________";
		cout << "\nFirstName: " << FirstName;
		cout << "\nLastName: " << LastName ;
		cout << "\nfullName: " << FullName ;
		cout << "\nEmail: " << Email ;
		cout << "\nPhone: " << Phone;
		cout << "\n_____________________";
	}*/
};

