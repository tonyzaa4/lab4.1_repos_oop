#pragma once
#include "Curve.h"

class Line : public Curve {
public:
    Line(double a_val, double b_val);

    // Перевизначення абстрактних методів
    bool contains(double x, double y) const override;
    void printEquation() const override;
};