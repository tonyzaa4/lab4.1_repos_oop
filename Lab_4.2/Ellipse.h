#pragma once
#include "Curve.h"

class Ellipse : public Curve {
public:
    Ellipse(double a_val, double b_val);

    bool contains(double x, double y) const override;
    void printEquation() const override;
};