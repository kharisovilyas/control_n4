#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class StringEnum {
    nonexist = 0,
    correct = 1,
    exitp = 2,
    nonexist_item_menu = 3,
    returnp = 4,
    returnin = 5,
    correct_impl = 7,
    non_fin_inital = 8,
    correct_out = 9
};

class StringEnumHelper {
public:
    StringEnumHelper() = default;
    StringEnumHelper(StringEnum e) : m_e(e) {}

    bool operator==(const StringEnumHelper& other) const {
        return m_e == other.m_e;
    }

    bool operator!=(const StringEnumHelper& other) const {
        return m_e != other.m_e;
    }

    friend ostream& operator<< (ostream& os, const StringEnumHelper& se) {
        os << static_cast<string>(se);
        return os;
    }

    operator std::string() const {
        switch (m_e) {
        case StringEnum::nonexist:
            return "\n����� � ����� ������ �� ����������!\n";

        case StringEnum::correct:
            return "\n������ ������� ��������!\n";

        case StringEnum::exitp:
            return "\n�� ����� �� ���������.\n";

        case StringEnum::returnp:
            return "\n�� ��������� � ���������� ������.\n";

        case StringEnum::returnin:
            return "\n�� ��������� � ����� ������.\n";

        case StringEnum::correct_impl:
            return "\n������ ���� ���������.\n";

        case StringEnum::non_fin_inital:
            return "\n�� ������ �� ��������� �������� ������.\n";
        case StringEnum::correct_out:
            return "\n������ ������� ���������.\n";
        default:
            return "\n��� �� ����� �� ���!\n";
        }
    }

private:
    StringEnum m_e;
};
