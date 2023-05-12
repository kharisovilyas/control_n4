#include "test.h"
#include "ui.h"
#include <fstream>
#include <sstream>

using namespace interaction;

enum {
	sizeOfTest = 5
};

enum {
	withoutEnd = 1, countTest = 6
};

template<typename T, typename U>

void printInvalid(T received, U expected, string message) {
	cout << message << endl;
	cout << "ќжидалось: " << expected << endl << "Ѕыло получено: " << received << endl;
}

void printInvalidResults(StringEnumHelper _expected, StringEnumHelper _received, string message) {
	string received = static_cast<string> (_received);
	string expected = static_cast<string> (_expected);
	cout << message << endl;
	cout << "ќжидалось: " << expected << endl << "Ѕыло получено: " << received << endl;
}

void createTestFile() {
    ofstream out("test1.txt");
	out << "aaaaaaaaaAAAAAAAAAaaaaaaaaaaa\naaaaaaAAAAAAaaaaaaAAAAAAAAAAA";
    out.close();

    ofstream out2("test2.txt");
	out2 << "llllaaaallllssskdjahdddjjjfff" << endl;
	out2 << "llllaaaallllssskdjahdddjjjfff" << endl;
	out2 << "llllaaaallllssskdjahdddjjjfff" << endl;
	out2 << "llllaaaallllssskdjahdddjjjfff" << endl;
	out2 << "llllaaaallllssskdjahdddjjjfff" << endl;
	out2 << "llllaaaallllssskdjahdddjjjfff" << endl;
	out2 << "llllaaaallllssskdjahdddjjjfff" << endl;
    out2.close();
}

bool testFillFromFile() {
	bool correct = true;
	freader fr{};
	string firstTest = "aaaaaaaaaAAAAAAAAAaaaaaaaaaaa\naaaaaaAAAAAAaaaaaaAAAAAAAAAAA";
	string secondTest = "llllaaaallllssskdjahdddjjjfff";
	unique_ptr<MyString> myString = make_unique<MyString>();
	stringstream buffer{};
	streambuf* old_cout_buf = cout.rdbuf(buffer.rdbuf());
	createTestFile();
	string message = "Ѕыл не пройден тест на коректные данные";
	istringstream input("test1.txt\n");
	cin.rdbuf(input.rdbuf());
	fr.inputFromFile(myString);
	if (myString->getOriginalString()[12] != firstTest[12]) {
		printInvalid(
			myString->getOriginalString()[12], firstTest[12], message
		);
		correct = false;

	}
	if (myString->getOriginalString()[30] != firstTest[30]) {
		printInvalid(
			myString->getOriginalString()[30], firstTest[30], message
		);
		correct = false;

	}
	if (myString->getOriginalString()[54] != firstTest[55]) {
		printInvalid(
			myString->getOriginalString()[54], firstTest[55], message
		);
		correct = false;

	}
	myString = {};
	myString = make_unique<MyString>();
	istringstream input2("test2.txt\n");
	cin.rdbuf(input2.rdbuf());
	fr.inputFromFile(myString);
	if (myString->getOriginalString()[28] != secondTest[28]) {
		printInvalid(
			myString->getOriginalString()[28], secondTest[28], message
		);
		correct = false;
	}
	if (myString->getOriginalString()[184] != secondTest[4]) {
		printInvalid(
			myString->getOriginalString()[184], secondTest[4], message
		);
		correct = false;

	}
	cin.rdbuf(cin.rdbuf());
	cout.rdbuf(old_cout_buf);
	return correct;
}

void generateSynt(string& str) {
	for (int i = 0; i < 100; i++) {
		if (i < 10 || i > 90) {
			str[i] = 'a';
		}
		if (i > 10 && i < 35) {
			str[i] = 'b';
		}
		if (i > 35 && i < 75) {
			str[i] = 'c';
		}
	}
}

bool testImplString(){
	bool correct = true;
	string myOriginalString = {};
	generateSynt(myOriginalString);
	unique_ptr<MyString> myString = make_unique<MyString>();
	stringstream buffer{};
	streambuf* old_cout_buf = cout.rdbuf(buffer.rdbuf());
	istringstream input("2\n");
	cin.rdbuf(input.rdbuf());
	myString->setOriginalString(myOriginalString);
	cin.rdbuf(cin.rdbuf());
	cout.rdbuf(old_cout_buf);
	return correct;

}
bool testSetOriginalString(){
	bool correct = true;
	return correct;
}
bool testSetQuantity() {
	bool correct = true;
	return correct;
}

StringEnumHelper test::startTest() {
	auto cinBuf = cin.rdbuf();
	if (
		testFillFromFile() &&
		testImplString() &&
		testSetOriginalString() &&
		testSetQuantity()
		) {

		cin.rdbuf(cinBuf);
		return StringEnumHelper(StringEnum::correct_test);
	}
	else {

		cin.rdbuf(cinBuf);
		return StringEnumHelper(StringEnum::correct_test);
	}
}