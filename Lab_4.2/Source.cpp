#include <iostream>
#include <Windows.h>
#include <typeinfo> // Обов'язково для виведення справжнього типу (typeid)

#include "Curve.h"
#include "Line.h"
#include "Ellipse.h"
#include "Hyperbola.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double test_x = 3.0;
    double test_y = 4.0;

    cout << "=== Тестування належностi точки (" << test_x << ", " << test_y << ") ===" << endl << endl;

    Line myLine(1.0, 1.0);       // y = 1*x + 1  => 4 = 1*3 + 1 (Точка належить)
   class  Ellipse myEllipse(5.0, 5.0);     // 3^2/25 + 4^2/25 = 9/25 + 16/25 = 25/25 = 1 (Точка належить)
    Hyperbola myHyperbola(3.0, 4.0); // 3^2/9 - 4^2/16 = 1 - 1 = 0 != 1 (Не належить)

    // масив вказівників на абстрактний клас
    const int SIZE = 3;
    Curve* curves[SIZE];

    curves[0] = &myLine;
    curves[1] = &myEllipse;
    curves[2] = &myHyperbola;

    for (int i = 0; i < SIZE; i++) {
        // виводення справжнього типу поліморфних об'єктів
        cout << "Справжнiй тип об'єкта: " << typeid(*curves[i]).name() << endl;

        cout << "Рiвняння: ";
        curves[i]->printEquation(); // поліморфний виклик
        cout << endl;

        // перевірка точки
        if (curves[i]->contains(test_x, test_y)) {
            cout << "Результат: Точка НАЛЕЖИТЬ кривiй." << endl;
        }
        else {
            cout << "Результат: Точка НЕ належить кривiй." << endl;
        }
    }

    return 0;
}