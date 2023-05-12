#pragma once
#include <iostream>
#include "MyString.h"
#include "StringEnumHelper.h"
using namespace std;

namespace menu {
	class loopedMenu {
	public:
		enum class inWay {
			EXITP = 3,
			FIN = 1,
			CIN = 2,
		};
		enum class outWay {
			RETURNP = 3,
			FOUT = 1,
			COUT = 2
		};
		enum class implWay {
			RETURNP = 2,
			IMPL = 1
		};

		void launchMenu();

		friend istream& operator>>(istream& is, outWay& value) {
			int input;
			is >> input;

			if (input == static_cast<int>(outWay::RETURNP) ||
				input == static_cast<int>(outWay::FOUT) ||
				input == static_cast<int>(outWay::COUT)) {
				value = static_cast<outWay>(input);
			}
			else {
				cout << "Некорректный ввод. Попробуйте еще раз" << endl;
				while (input != static_cast<int>(outWay::RETURNP) &&
					input != static_cast<int>(outWay::FOUT) &&
					input != static_cast<int>(outWay::COUT)) {
					is.clear();
					is.ignore(INT_MAX, '\n');
					cout << "Ввод: ";
					is >> input;
				}
				value = static_cast<outWay>(input);
			}

			is.ignore(INT_MAX, '\n');
			return is;
		}
		friend 	istream& operator>>(istream& is, inWay& value) {
			int input;
			is >> input;

			if (input == static_cast<int>(inWay::EXITP) ||
				input == static_cast<int>(inWay::FIN) ||
				input == static_cast<int>(inWay::CIN)) {

				value = static_cast<inWay>(input);
			}
			else {
				cout << "Некорректный ввод. Попробуйте еще раз" << endl;
				while (input != static_cast<int>(inWay::EXITP) &&
					input != static_cast<int>(inWay::FIN) &&
					input != static_cast<int>(inWay::CIN)) {
					is.clear();
					is.ignore(INT_MAX, '\n');
					cout << "Ввод: ";
					is >> input;
				}
				value = static_cast<inWay>(input);
			}

			is.ignore(INT_MAX, '\n');
			return is;
		}
		friend 	istream& operator>>(istream& is, implWay& value) {
			int input;
			is >> input;

			if (input == static_cast<int>(implWay::RETURNP) ||
				input == static_cast<int>(implWay::IMPL)) {
				value = static_cast<implWay>(input);
			}
			else {
				cout << "Некорректный ввод. Попробуйте еще раз" << endl;
				while (input != static_cast<int>(implWay::RETURNP) &&
					input != static_cast<int>(implWay::IMPL)) {
					is.clear();
					is.ignore(INT_MAX, '\n');
					cout << "Ввод: ";
					is >> input;
				}
				value = static_cast<implWay>(input);
			}

			is.ignore(INT_MAX, '\n');
			return is;
		}
	};
}