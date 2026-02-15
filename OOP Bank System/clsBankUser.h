#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include<vector>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
class clsBankUser :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;
	bool _MarkedForDelete = false;



	static clsBankUser _ConviretLineToUserObject(string line) {
		vector<string> vUser = clsString::Split(line, "#//#");
		return clsBankUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stoi(vUser[6]));
	}
	static clsBankUser _GetEmptyObject() {
		return clsBankUser(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);
	}
	string _ConvertObjectToLine(clsBankUser client, string delim = "#//#") {
		string UserLine = "";
		UserLine += client.FirstName + delim;
		UserLine += client.LastName + delim;
		UserLine += client.Email + delim;
		UserLine += client.Phone + delim;
		UserLine += client.UserName + delim;
		UserLine += client.Password + delim;
		UserLine += to_string(client.Permission);
		return UserLine;
	}
	static vector<clsBankUser> _LoadUsersFromFile() {
		vector<clsBankUser> vUsers;
		fstream myFile;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankUser user = _ConviretLineToUserObject(line);
				vUsers.push_back(user);
			}
			myFile.close();
		}
		return vUsers;
	}
	void _SaveUsersToFile(vector<clsBankUser> vUsers) {
		fstream myFile;
		myFile.open("Users.txt", ios::out);
		string Dataline;

		if (myFile.is_open()) {
			for (clsBankUser& C : vUsers) {
				if (C._MarkedForDelete == false) {
					Dataline = _ConvertObjectToLine(C);
					myFile << Dataline << "\n";
				}
			}
			myFile.close();
		}
	}
	void _Update() {
		vector<clsBankUser> vUsers;
		vUsers = _LoadUsersFromFile();
		for (clsBankUser& U : vUsers) {
			if (U.UserName == _UserName) {
				U = *this;
				break;
			}
		}
		_SaveUsersToFile(vUsers);
	}

	void AddDataLineToFile(string UserLine) {
		fstream myFile;
		myFile.open("Users.txt", ios::out | ios::app);
		if (myFile.is_open()) {
			myFile << UserLine << "\n";
			myFile.close();
		}
	}
	void _AddNew() {
		AddDataLineToFile(_ConvertObjectToLine(*this));
	}

public:
	 enum enPermissions {
		eAll = -1,
		eClientsList = 1,
		eAddNewClient = 2,
		eDeleteClient = 4,
		eUpdateClient = 8,
		eFindClient = 16,
		eTransaction = 32,
		eManageUsers = 64,
	};
	  bool CheckAccessPermission(enPermissions permission) {
		if (this->Permission  == enPermissions::eAll)return true;
		if ((permission & this->Permission) == permission)
			return true;
		else 
			return false;

	}
	clsBankUser(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permission) :
		clsPerson(firstName, lastName, email, phone) {
		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permission = permission;
	}
	//////////
	bool isEmpty() {
		return _Mode == enMode::EmptyMode;
	}
	//////////
	string getUserName() {
		return _UserName;
	}
	__declspec(property(get = getUserName)) string UserName;
	//////////
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	//////////
	void setPassword(string password) {
		_Password = password;
	}
	string getPassword() {
		return _Password;
	}
	__declspec(property(get = getPassword, put = setPassword)) string Password;
	///////////
	void setPermission(int permission) {
		_Permission = permission;
	}
	int getPermission() {
		return _Permission;
	}
	__declspec(property(get = getPermission, put = setPermission)) int Permission;
	///////////

	static clsBankUser Find(string userName) {
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open()) {
			string userLine = "";
			while (getline(myfile, userLine)) {
				clsBankUser User = _ConviretLineToUserObject(userLine);
				if (User.UserName == userName) {
					myfile.close();
					return User;
				}
			}
			myfile.close();
		}

		return _GetEmptyObject();
	}
	static clsBankUser Find(string userName, string password) {
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open()) {
			string userLine = "";
			while (getline(myfile, userLine)) {
				clsBankUser User = _ConviretLineToUserObject(userLine);
				if (User.UserName == userName && User.Password == password) {
					myfile.close();
					return User;
				}
			}
			myfile.close();
		}

		return _GetEmptyObject();
	}
	static bool IsUserExist(string userName) {
		clsBankUser User = clsBankUser::Find(userName);

		return !(User.isEmpty());
	}
	static bool IsUserExist(string userName, string password) {
		clsBankUser User = clsBankUser::Find(userName, password);

		return !(User.isEmpty());
	}
	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
	enSaveResult Save() {
		switch (_Mode) {
		case enMode::AddNewMode: {
			if (clsBankUser::IsUserExist(_UserName)) {
				return enSaveResult::svFaildUserExists;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		case enMode::UpdateMode: {
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case enMode::EmptyMode: {
			if (isEmpty()) {
				return enSaveResult::svFaildEmptyObject;
			}
			break;
		}
		}
	}
	bool Delete() {
		vector<clsBankUser> vUsers;
		vUsers = _LoadUsersFromFile();
		for (clsBankUser& U : vUsers) {
			if (U.UserName == _UserName) {
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersToFile(vUsers);
		*this = _GetEmptyObject();
		return true;
	}
	static clsBankUser _GetAddNewObject(string userName) {
		return clsBankUser(enMode::AddNewMode, " ", " ", " ", " ", userName, " ", 0);
	}
	static vector <clsBankUser> GetUsersList()
	{
		return _LoadUsersFromFile();
	}
	
	
};

