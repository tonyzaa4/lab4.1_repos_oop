#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4.2/Line.h"
#include "../Lab_4.2/Hyperbola.h"
#include "../Lab_4.2/Line.cpp"
#include "../Lab_4.2/Hyperbola.cpp"
#include "../Lab_4.2/Curve.h"
#include "../Lab_4.2/Curve.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab41UnitTests
{
    TEST_CLASS(LineTests)
    {
    public:
        TEST_METHOD(TestPointOnLine)
        {
            Line l(2.0, 1.0); // Рівняння: y = 2x + 1

            // Якщо x = 2, то y має бути 5 (2*2 + 1 = 5)
            Assert::IsTrue(l.contains(2.0, 5.0));
        }

        TEST_METHOD(TestPointNotOnLine)
        {
            Line l(2.0, 1.0); // Рівняння: y = 2x + 1

            // Якщо x = 2, а y = 6, точка не лежить на прямій
            Assert::IsFalse(l.contains(2.0, 6.0));
        }
    };

    TEST_CLASS(HyperbolaTests)
    {
    public:
        TEST_METHOD(TestPointOnHyperbola)
        {
            Hyperbola h(3.0, 4.0);

            // Якщо x = 3, y = 0 -> 9/9 - 0 = 1
            Assert::IsTrue(h.contains(3.0, 0.0));
        }

        TEST_METHOD(TestPointNotOnHyperbola)
        {
            Hyperbola h(3.0, 4.0);

            // Якщо x = 0, y = 4 -> 0 - 16/16 = -1 (а не 1)
            Assert::IsFalse(h.contains(0.0, 4.0));
        }
    };

    TEST_CLASS(PolymorphismTests)
    {
    public:
        TEST_METHOD(TestDynamicBinding)
        {
            Line l(1.0, 0.0); // Пряма y = x

            Curve* ptr = &l;

            Assert::IsTrue(ptr->contains(5.0, 5.0));   // Належить y = x
            Assert::IsFalse(ptr->contains(5.0, 10.0)); // Не належить
        }
    };
}