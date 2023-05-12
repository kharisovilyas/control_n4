#include "MyString.h"
#include <string>
#include "ui.h"
#include <iostream>
using namespace ui;

string MyString::getOriginalString() {
    return originalString;
}

string MyString::getResultString() {
    return resultString;
}

void MyString::setQuantity(int q) {
	quantity = q;
}

void MyString::setOriginalString(string str) {
    originalString = str;
}

void MyString::findAndReplaceSequences() {
    int minLength = quantity;
    int count = 1;
    for (int i = 1; i <= originalString.length(); i++) {
        char prevChar = originalString[i-1];
        if (originalString[i] == prevChar) {
            count++;
        }
        else {
            if (count >= minLength) {
                resultString += "{" + string(1, prevChar) + ", " + to_string(count) + "}";
            }
            else {
                int curr = i - count;
                int end = count;
                resultString += originalString.substr(curr, end);
            }
            count = 1;
        }
    }
}
