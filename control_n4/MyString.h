#pragma once
#include <iostream>
using namespace std;

class MyString {
private:
	string originalString{};
	string resultString{};
	int quantity{};
	char symbol{};

public:
	MyString() = default;
	string getOriginalString();
	string getResultString();
	void setQuantity(int);
	void findAndReplaceSequences();
	void setOriginalString(string);
};