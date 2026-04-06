#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(double a_val, double b_val) : Curve(a_val, b_val) {
    // Захист від ділення на нуль
    if (a == 0) a = 1;
    if (b == 0) b = 1;
}

bool Ellipse::contains(double x, double y) const {
    // Рівняння: x^2/a^2 + y^2/b^2 = 1
    double left_side = (x * x) / (a * a) + (y * y) / (b * b);
    return std::abs(left_side - 1.0) < 1e-6;
}

void Ellipse::printEquation() const {
    cout << "x^2/" << a * a << " + y^2/" << b * b << " = 1";
}