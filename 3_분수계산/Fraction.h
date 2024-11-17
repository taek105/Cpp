#pragma once

using namespace std;

class Fraction
{
private:
    int numer;
    int denom;

public:
    Fraction();
    Fraction(int num, int dem);
    void setDenom(int den);
    void setNumer(int num);
    const Fraction add(const Fraction& f1) const;
    int getGCD(int a, int b);
    void print();
};