#include <iostream>
#include "ui.h"

using namespace interaction;
using namespace ui;

template<typename T>
T getInput() {
	T userInput = 0;
	cout << "����: ";
	cin >> userInput;
	if (cin.fail()) {
		cout << "����������� ����. ���������� ��� ���" << endl;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "����: ";
			cin >> userInput;
		}
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}

int correctness::getInt() {
	return getInput<int>();
}

bool correctness::getBool() {
	return getInput<bool>();
}

double correctness::getDouble() {
	return getInput<double>();
}

int correctness::getIntField() {
	correctness check;
	bool inputCorrect = false;
	int in = 0;
	while (!inputCorrect) {
		in = check.getInt();
		if (in >= 1) {
			inputCorrect = true;
		}
		else {
			cout << "������� ��������������� �����! ���������� ��� ���" << endl;
		}
	}
	return in;
}

double correctness::getDoubleField() {
	correctness check;
	bool inputCorrect = false;
	double in = 0;
	while (!inputCorrect) {
		in = check.getDouble();
		if (in >= 1) {
			inputCorrect = true;
		}
		else {
			cout << "������� ��������������� �����! ���������� ��� ���" << endl;
		}
	}
	return in;
}