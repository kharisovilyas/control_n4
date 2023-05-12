#include "ui.h"
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace interaction;
using namespace std;

StringEnumHelper freader::inputFromFile(unique_ptr<MyString>& myString) {
	string nameOfFile{};
	string data{};
	string _data{};
	ui::cinNameOfFile();
	getline(cin, nameOfFile);
	ifstream input;
	input.open(nameOfFile);
	if (input.is_open()) {
		while (getline(input, data)) {
			if (_data.empty()) { _data += data; }
			_data = _data + '\n' + data;
		}
	}else {
		return StringEnumHelper(StringEnum::nonexist);
	}
	myString->setOriginalString(_data);
	return StringEnumHelper(StringEnum::correct);
}

StringEnumHelper freader::onInitalDataOutputInFile(unique_ptr<MyString>& myString) {
	ui::correctness correct{};
	ui::coutInfoOnInital();
	if (correct.getBool()) {
		return outputInFile(myString, true);
	}
	else {
		return StringEnumHelper(StringEnum::non_fin_inital);
	}
}

StringEnumHelper freader::outputInFile(unique_ptr<MyString>& myString, bool initalData) {
	string filePath = "";
	bool isDataSaved = false;
	ui::correctness check;
	do {
		ui::saveIn();
		getline(cin, filePath);

		if (ifstream(filePath)) {
			ui::fileExist();
			int tryAnotherFile = check.getBool();
			if (tryAnotherFile) {
				continue;
			}
		}

		ofstream myFile(filePath, ofstream::app);

		error_code ec{};

		if (!myFile) {
			ui::dataNotSave();
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filePath, ofstream::trunc);
		if (initalData) {
			myFile << myString->getOriginalString();
		}
		else {
			myFile << "Ваш исходный текст: " << endl;
			myFile << endl << myString->getOriginalString() << endl;
			myFile << endl <<"Преобразованный текст: " << endl;
			myFile << endl << myString->getResultString();
		}
		myFile.close();
		ui::dataSave();
		isDataSaved = true;
	} while (!isDataSaved);
	return StringEnumHelper(StringEnum::correct_out);
}