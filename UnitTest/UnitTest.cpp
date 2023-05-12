#include "pch.h"
#include "CppUnitTest.h"
#include "..\control_n4\menu.h"
#include "..\control_n4\MyString.h"
#include "..\control_n4\MyString.cpp"
#include "..\control_n4\StringEnumHelper.h"
#include "..\control_n4\ui.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(MyStringTest)
    {
    public:
        TEST_METHOD(getOriginalStringTest)
        {
            MyString myString;
            myString.setOriginalString("test");
            Assert::AreEqual(myString.getOriginalString(), std::string("test"));
        }

        TEST_METHOD(getResultStringTest)
        {
            MyString myString;
            myString.setOriginalString("aaabbbcc");
            myString.setQuantity(2);
            myString.findAndReplaceSequences();
            Assert::AreEqual(myString.getResultString(), std::string("{a, 3}{b, 3}{c, 2}"));
        }

        TEST_METHOD(setOriginalStringTest)
        {
            MyString myString;
            myString.setOriginalString("test");
            Assert::AreEqual(myString.getOriginalString(), std::string("test"));
        }

        TEST_METHOD(findAndReplaceSequencesTest)
        {
            MyString myString;

            myString.setOriginalString("aaabbbccc");
            myString.setQuantity(2);
            myString.findAndReplaceSequences();
            Assert::AreEqual(myString.getResultString(), std::string("{a, 3}{b, 3}{c, 3}"));

            myString = {};
            myString.setOriginalString("aaabbbcc");
            myString.setQuantity(3);
            myString.findAndReplaceSequences();
            Assert::AreEqual(myString.getResultString(), std::string("{a, 3}{b, 3}cc"));

            myString = {};
            myString.setOriginalString("abc");
            myString.setQuantity(2);
            myString.findAndReplaceSequences();
            Assert::AreEqual(myString.getResultString(), std::string("abc"));

            myString = {};
            myString.setOriginalString("aa");
            myString.setQuantity(2);
            myString.findAndReplaceSequences();
            Assert::AreEqual(myString.getResultString(), std::string("{a, 2}"));

            myString = {};
            myString.setOriginalString("");
            myString.setQuantity(2);
            myString.findAndReplaceSequences();
            Assert::AreEqual(myString.getResultString(), std::string(""));
        }
    };
    TEST_CLASS(StringEnumHelperTest)
    {
    public:
        TEST_METHOD(EqualityOperatorTest)
        {
            StringEnumHelper first(StringEnum::nonexist);
            StringEnumHelper second(StringEnum::nonexist);
            StringEnumHelper third(StringEnum::correct);

            Assert::IsTrue(first == second);
            Assert::IsFalse(first == third);
        }

        TEST_METHOD(InequalityOperatorTest)
        {
            StringEnumHelper first(StringEnum::nonexist);
            StringEnumHelper second(StringEnum::nonexist);
            StringEnumHelper third(StringEnum::correct);

            Assert::IsFalse(first != second);
            Assert::IsTrue(first != third);
        }

        TEST_METHOD(StreamOperatorTest)
        {
            StringEnumHelper se(StringEnum::correct);

            std::stringstream stream;
            stream << se;

            Assert::AreEqual(stream.str(), std::string("\nДанные успешно записаны!\n"));
        }

        TEST_METHOD(StringConversionOperatorTest)
        {
            StringEnumHelper se(StringEnum::nonexist);

            std::string str = se;

            Assert::AreEqual(str, std::string("\nФайла с таким именем не существует!\n"));
        }
    };
}
