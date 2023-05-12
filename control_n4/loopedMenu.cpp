#include "ui.h"
#include "menu.h"
#include "StringEnumHelper.h"

using namespace interaction;
using namespace ui;
using namespace menu;


StringEnumHelper selectInput(loopedMenu::inWay variant, unique_ptr<MyString>& myString) {
    freader fr{};
    creader cr{};
    switch (variant)
    {
    case loopedMenu::inWay::EXITP:
        return StringEnumHelper(StringEnum::exitp);
    case loopedMenu::inWay::FIN:
        return fr.inputFromFile(myString);
    case loopedMenu::inWay::CIN:
        return cr.inputFromConsole(myString);
    default:
        return StringEnumHelper(StringEnum::nonexist_item_menu);
    }
}

StringEnumHelper selectOutput(loopedMenu::outWay variant, unique_ptr<MyString>& myString) {
    freader fr{};
    creader cr{};
    switch (variant)
    {
    case loopedMenu::outWay::RETURNP:
        return StringEnumHelper(StringEnum::exitp);
    case loopedMenu::outWay::FOUT:
        return fr.outputInFile(myString, false);
    case loopedMenu::outWay::COUT:
        return cr.outputInConsole(myString);
    default:
        return StringEnumHelper(StringEnum::nonexist_item_menu);
    }
}

StringEnumHelper selectImpl(loopedMenu::implWay variant, unique_ptr<MyString>& myString) {
    implementation impl{};
    switch (variant)
    {
    case menu::loopedMenu::implWay::RETURNP:
        return StringEnumHelper(StringEnum::returnin);

    case menu::loopedMenu::implWay::IMPL:
        return impl.implTask(myString);

    default:
        return StringEnumHelper(StringEnum::nonexist_item_menu);
    }
}

void outputOriginalString(unique_ptr<MyString>& myString) {
    ui::returnOriginalString();
    correctness correct{};
    creader cr{};
    if (correct.getBool()) {
        cr.outputOriginalString(myString);
    }
}


void loopedMenu::launchMenu() {
    inWay inVar{};
    outWay outVar{};
    implWay implVar{};
    StringEnumHelper processInput{};
    StringEnumHelper processImpl{};
    StringEnumHelper processOutput{};
    StringEnumHelper outProgramm = StringEnumHelper(StringEnum::exitp);
    StringEnumHelper returnProgramm = StringEnumHelper(StringEnum::returnp);
    StringEnumHelper returnToIn = StringEnumHelper(StringEnum::returnin);
    unique_ptr<MyString> myString = make_unique<MyString>();
    //input
    do
    {
        *myString = {};
        ui::printInputWays();
        cin >> inVar;
        processInput = selectInput(inVar, myString);
        if (processInput == outProgramm) {
            cout << processInput << endl;
            break;
        }
        cout << processInput << endl;
        //implementation task
        do {

            ui::printActionWays();
            cin >> implVar;
            processImpl = selectImpl(implVar, myString);
            if (processImpl == returnToIn) {
                cout << processImpl << endl;
                break;
            }
            cout << processImpl << endl;
            //output
            do {
                ui::printOutputWays();
                cin >> outVar;
                processOutput = selectOutput(outVar, myString);
                if (processOutput == returnProgramm) {
                    cout << processOutput << endl;
                    break;
                }
                cout << processOutput << endl;
                outputOriginalString(myString);

            } while (outVar != outWay::RETURNP);

        } while (implVar != implWay::RETURNP);

    } while (inVar != inWay::EXITP);
}