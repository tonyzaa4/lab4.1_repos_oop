#include "Line.h"
#include <cmath>

Line::Line(double a_val, double b_val) : Curve(a_val, b_val) {}

bool Line::contains(double x, double y) const {
    // Рівняння: y = ax + b
    // epsilon для порівняння
    double expected_y = a * x + b;
    return std::abs(y - expected_y) < 1e-6;
}

void Line::printEquation() const {
    cout << "y = " << a << "*x + " << b;
}