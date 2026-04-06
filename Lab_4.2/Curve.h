#pragma once
#include <iostream>
#include <string>

using namespace std;

class Curve {
protected:
    double a;
    double b;

public:
    Curve(double a_val, double b_val);

    virtual ~Curve();

    // Чисто віртуальна функція (= 0 робить клас абстрактним)
    virtual bool contains(double x, double y) const = 0;

    virtual void printEquation() const = 0;
};