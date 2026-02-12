#pragma once
#include<iostream>
#include<vector>
using namespace std;


enum eTrim { trimLeft, trimRight, TrimTowSides };
class clsString
{
private:
	string _Value;

public:
	clsString() {}
	clsString(string value) {
		_Value = value;
	}

	void setString(string value) {
		_Value = value;
	}
	string getString() {
		return _Value;
	}
	__declspec(property(get = getString, put = setString)) string Value;
	/////////////////////////////////
	static int Length(string S) {
		return S.length();
	}
	int Length() {
		return Length(_Value);
	}
	//////////////////////////23
	static void PrintFirstLetterOfEachWord(string S) {
		bool isFirstLetter = true;
		cout << "the first letter of each word: " << endl;
		for (int i = 0; i < S.length(); i++) {

			if (S[i] != ' ' && isFirstLetter) {
				cout << S[i] << endl;
			}
			isFirstLetter = S[i] == ' ' ? true : false;

		}

	}
	void PrintFirstLetterOfEachWord() {
		PrintFirstLetterOfEachWord(_Value);
	}
	/////////////////////////24
	static string UpperFirstLetterOfEachWord(string S) {
		bool isFirstLetter = true;
		cout << "\nUpper first letter of each word in thr string: " << endl;
		for (int i = 0; i < S.length(); i++) {

			if (S[i] != ' ' && isFirstLetter) {
				S[i] = toupper(S[i]);
			}
			isFirstLetter = S[i] == ' ' ? true : false;

		}
		return S;
	}
	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	}
	////////////////////////25
	static string LowerFirstLetterOfEachWord(string S) {
		bool IsFirstLetter = true;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && IsFirstLetter) {
				S[i] = tolower(S[i]);
			}
			IsFirstLetter = S[i] == ' ' ? true : false;
		}
		return S;
	}
	void LowerFirstLetterOfEachWord() {
		_Value = LowerFirstLetterOfEachWord(_Value);
	}
	////////////////////////26
	static string UpperAllString(string S) {
		for (int i = 0; i < S.length(); i++) {
			S[i] = toupper(S[i]);
		}
		return S;
	}
	void UpperAllString() {
		_Value = UpperAllString(_Value);
	}
	///
	static string LowerAllString(string S) {
		for (int i = 0; i < S.length(); i++) {
			S[i] = tolower(S[i]);
		}
		return S;
	}
	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}
	/////////////////////////27
	static char InvertCaracter(char C) {
		return islower(C) ? toupper(C) : tolower(C);
	}
	/////////////////////////28
	static string InvertString(string S) {
		for (int i = 0; i < S.length(); i++) {
			S[i] = InvertCaracter(S[i]);
		}
		return S;
	}
	void InvertString() {
		_Value = InvertString(_Value);
	}
	//////////////////////////29
	static int CountLetters(string S) {
		int count = 0;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] != ' ' && !ispunct(S[i]))count++;
		}
		return count;
	}
	int CountLetters() {
		return CountLetters(_Value);
	}
	/////////////////////////////////////////
	enum eWhatToCount { AllLetters, CountCapitalLetter, CountSmallLetter };

	static int CountLettersInString(string S, eWhatToCount enKindOfCount = eWhatToCount::AllLetters) {
		int count = 0;
		if (enKindOfCount == eWhatToCount::AllLetters) {
			return CountLetters(S);
		}
		for (int i = 0; i < S.length(); i++) {
			if (enKindOfCount == eWhatToCount::CountCapitalLetter && isupper(S[i])) {
				count++;
			}
			if (enKindOfCount == eWhatToCount::CountSmallLetter && islower(S[i])) {
				count++;
			}
		}
		return count;

	}
	static int CountCapitalLetters(string S) {
		return CountLettersInString(S, eWhatToCount::CountCapitalLetter);
	}
	int CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}
	static int CountSmallLetters(string S) {
		return CountLettersInString(S, eWhatToCount::CountSmallLetter);
	}
	int CountSmallLetters() {
		return CountSmallLetters(_Value);
	}
	int CountLettersInString() {
		return CountLettersInString(_Value, eWhatToCount::AllLetters);
	}

	//////////////////////////////////////////30
	static int CountSpecificIetter(string S, char C, bool MatchCase = true) {
		int count = 0;
		for (int i = 0; i < S.length(); i++) {
			if (MatchCase) {
				if (S[i] == C)count++;

			}
			else {
				if (tolower(S[i]) == tolower(C)) count++;
			}
		}
		return count;
	}
	int CountSpecificIetter(char C, bool MatchCase = true) {
		return  CountSpecificIetter(_Value, C, MatchCase);
	}

	/////////////////////////////////32
	static bool IsVowel(char c) {
		char vowelCharacter[5] = { 'a','o','i','u','e' };
		for (short i = 0; i < 5; i++) {
			if (tolower(c) == vowelCharacter[i]) {
				return true;
			}
		}
		return false;
	}
	///////////////////////////////////////33
	static int CountVowelLetters(string S) {
		int count = 0;
		for (short i = 0; i < S.length(); i++) {
			if (IsVowel(S[i])) {
				count++;
			}
		}
		return count;
	}
	int CountVowelLetters() {
		return CountVowelLetters(_Value);
	}
	///////////////////////////////////////34
	static void PrintVowelLetters(string S) {
		for (short i = 0; i < S.length(); i++) {
			if (IsVowel(S[i])) {
				cout << S[i] << "  ";
			}
		}
		cout << "\n";

	}
	void PrintVowelLetters() {
		PrintVowelLetters(_Value);
	}

	//////////////////////////////////36
	static int CountWords(string S, string delim = " ") {
		string word = "";
		short pos = 0;
		int count = 0;
		while ((pos = S.find(delim)) != std::string::npos) {
			word = S.substr(0, pos);
			if (word != "") {
				count++;
			}
			S.erase(0, pos + delim.length());
		}
		if (S != " ") {
			count++;
		}
		return count;
	}
	int CountWords() {
		return CountWords(_Value);
	}
	//////////////////////////////////37
	static vector<string> Split(string S, string delim = " ") {
		string word = "";
		short pos = 0;
		vector<string> vWords;
		while ((pos = S.find(delim)) != std::string::npos) {
			word = S.substr(0, pos);
			if (word != "") {
				vWords.push_back(word);
			}
			S.erase(0, pos + delim.length());
		}
		if (S != " ") {
			vWords.push_back(S);
		}
		return vWords;
	}
	vector<string> Split() {
		return Split(_Value);
	}
	//////////////////////////////////38
	static string TrimLeft(string S) {
		for (short i = 0; i < S.length() - 1; i++) {
			if (S[i] != ' ') {
				return S.substr(i, S.length() - i);
			}
		}
		return S;
	}
	static string TrimRight(string S) {
		for (short i = S.length() - 1; i >= 0; i--) {
			if (S[i] != ' ') {
				return S.substr(0, i + 1);
			}
		}
		return S;
	}

	static string Trim(string S, eTrim Trim = eTrim::TrimTowSides) {
		if (Trim == eTrim::TrimTowSides) {
			return TrimRight(TrimLeft(S));
		}
		else if (Trim == eTrim::trimLeft) {
			return TrimLeft(S);
		}
		else if (Trim == eTrim::trimRight) {
			return TrimRight(S);
		}
	}
	void TrimLeft() {
		_Value = Trim(_Value, eTrim::trimLeft);
	}
	void TrimRight() {
		_Value = Trim(_Value, eTrim::trimRight);
	}
	void  Trim() {
		_Value = Trim(_Value, eTrim::TrimTowSides);
	}
	//////////////////////////////////39
	static string jounString(vector<string> vWords, string delim) {
		string line = "";
		for (string& Item : vWords) {
			line += (Item + delim);
		}
		return line.substr(0, line.length() - delim.length());
	}
	static string jounString(string arrString[], short length, string delim) {
		string line = "";
		for (short i = 0; i < length; i++) {
			line = line + arrString[i] + delim;
		}
		return line.substr(0, line.length() - delim.length());
	}

	////////////////////////////////41
	static string ReverseWordsInString(string S) {
		vector<string> Vwords = Split(S);
		int counWord = CountWords(S);
		string reversString = "";
		for (int i = counWord; i > 0; i--) {
			reversString = reversString + Vwords[i - 1] + " ";
		}
		return Trim(reversString, eTrim::trimRight);
	}
	void ReverseWordsInString() {
		_Value = ReverseWordsInString(_Value);
	}
	///////////////////////////////////42
	static string ReplaceWord(string S, string WordToReplace, string ReplaceToWord) {
		vector<string> vWords = Split(S);
		vector<string>::iterator iter = vWords.end();
		while (iter != vWords.begin()) {
			iter--;
			if (*iter == WordToReplace) {
				*iter = ReplaceToWord;
			}
		}
		return jounString(vWords, " ");
	}
	string ReplaceWord(string WordToReplace, string ReplaceToWord) {
		return ReplaceWord(_Value, WordToReplace, ReplaceToWord);
	}
	/////////////////////////////////////////43
	static string RemovePunctuations(string S) {
		string newS = "";
		for (int i = 0; i < S.length(); i++) {
			if (!ispunct(S[i])) {
				newS += S[i];
			}
		}
		return newS;
	}
	void RemovePunctuations() {
		_Value = RemovePunctuations(_Value);
	}
};




