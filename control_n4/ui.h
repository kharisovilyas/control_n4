#pragma once
#include <iostream>
#include "MyString.h"
#include "StringEnumHelper.h"
using namespace std;

namespace ui {
	class correctness {
	public:
		int getInt();
		bool getBool();
		double getDouble();
		int getIntField();
		double getDoubleField();
	};
	void testCorrect();
	void testIncorrect();
	void coutInfoOnInital();
	void cinNameOfFile();
	void coutResult();
	void coutOriginal();
	void foutResult();
	void cinContinue();
	void cinText();
	void cinQuantity();
	void printInputWays();
	void printActionWays();
	void printOutputWays();
	void outGretting();
	void dataSave();
	void dataNotSave();
	void fileExist();
	void saveIn();
	void returnOriginalString();
}
namespace interaction {
	class freader {
	public:
		StringEnumHelper inputFromFile(unique_ptr<MyString>&);
		StringEnumHelper outputInFile(unique_ptr<MyString>&, bool);
		StringEnumHelper onInitalDataOutputInFile(unique_ptr<MyString>&);
	};
	class creader {
	public:
		StringEnumHelper inputFromConsole(unique_ptr<MyString>&);
		StringEnumHelper outputInConsole(unique_ptr<MyString>&);
		void outputOriginalString(unique_ptr<MyString>&);
	};
	class implementation {
	public:
		StringEnumHelper implTask(unique_ptr<MyString>&);
	};
}