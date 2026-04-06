#pragma once
#include "Curve.h"

class Hyperbola : public Curve {
public:
    Hyperbola(double a_val, double b_val);

    bool contains(double x, double y) const override;
    void printEquation() const override;
};