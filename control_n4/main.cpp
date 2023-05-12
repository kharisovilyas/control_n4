#include <iostream>
#include "ui.h"
#include "menu.h"

using namespace std;
using namespace menu;

int main() {
	loopedMenu menu{};
	system("chcp 1251");
	setlocale(LC_ALL, "Rus");
	ui::outGretting();
	menu.launchMenu();
	system("pause");
}