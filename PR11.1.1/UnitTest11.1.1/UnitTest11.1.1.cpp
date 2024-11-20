#include "pch.h"
#include "CppUnitTest.h"
#include "../PR11.1.1/PR11.1.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1111
{
	TEST_CLASS(UnitTest1111)
	{
	public:
        TEST_METHOD(TestReplaceNo)
        {
            // Перевіряємо функцію ReplaceNo
            Assert::AreEqual(string("This is *** example"), ReplaceNo("This is no example"));
            Assert::AreEqual(string("No replacements"), ReplaceNo("No replacements")); // Без "no", без змін
            Assert::AreEqual(string("Nothing happens here"), ReplaceNo("Nothing happens here")); // Без змін
            Assert::AreEqual(string("Double *** detected"), ReplaceNo("Double no detected")); // Один збіг "no"
		}
	};
}
