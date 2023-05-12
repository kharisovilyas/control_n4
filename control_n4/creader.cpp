#include "ui.h"
#include "MyString.h"

using namespace interaction;

StringEnumHelper creader::inputFromConsole(unique_ptr<MyString>& myString) {
	ui::correctness correct{};
	freader fr{};
	string substr{};
	string str{};
	ui::cinText();
	while (getline(cin, substr)) {
		ui::cinContinue();
		if (correct.getBool()) {
			if (str.empty()) { str += substr; }
			str = str + '\n' + substr;
		}
		else {
			if (str.empty()) { str = substr; }
			break;
		}
	}
	myString->setOriginalString(str);

	return 
		fr.onInitalDataOutputInFile(myString);
}

StringEnumHelper creader::outputInConsole(unique_ptr<MyString>& myString) {
	ui::coutResult();
	cout << myString->getResultString();
	return StringEnumHelper(StringEnum::correct_out);
}

void creader::outputOriginalString(unique_ptr<MyString>& myString) {
	ui::coutOriginal();
	cout << myString->getOriginalString();
}