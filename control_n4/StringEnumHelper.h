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
            return "\nФайла с таким именем не существует!\n";

        case StringEnum::correct:
            return "\nДанные успешно записаны!\n";

        case StringEnum::exitp:
            return "\nВы вышли из программы.\n";

        case StringEnum::returnp:
            return "\nВы вернулись к исполнению задачи.\n";

        case StringEnum::returnin:
            return "\nВы вернулись к вводу текста.\n";

        case StringEnum::correct_impl:
            return "\nЗадача была выполнена.\n";

        case StringEnum::non_fin_inital:
            return "\nВы решили не сохранять исходные данные.\n";
        case StringEnum::correct_out:
            return "\nДанные успешно полученны.\n";
        default:
            return "\nЧто то пошло не так!\n";
        }
    }

private:
    StringEnum m_e;
};
