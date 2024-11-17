#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction::Fraction()
{
    numer = 1;
    denom = 1;
}

Fraction::Fraction(int num, int den)
{   
    int pmcnt = 0;

    if ( den == 0 ) 
    {
        cout << "분모를 1로 바꿈 \n";
        den = 1;
    }
    
    if ( num < 0 ) 
    {
        pmcnt ++; 
        num = -num;
    }
    if ( den < 0 ) 
    {
        pmcnt ++; 
        den = -den;
    }

    int gcd = getGCD(num, den);
    
    denom = den / gcd;
    numer = num / gcd;

    if ( pmcnt % 2 == 1 ) numer = -numer;
}

const Fraction Fraction::add(const Fraction& f2) const
{   
    Fraction res(numer * f2.denom + f2.numer * denom, denom * f2.denom);
    
    return res;
}

int Fraction::getGCD(int a, int b)
{   
    a = abs(a);
    b = abs(b);

    int gcd = a % b;
    while ( gcd > 0 )
    {
        a = b;
        b = gcd;
        gcd = a % b;
    }
    gcd = b;

    return gcd;
}

void Fraction::print()
{   
    if ( numer == 0 ) cout << 0;

    else cout << numer << " / " << denom << endl;
}

void Fraction::setNumer(int num)
{   
    if ( numer < 0 ) num = -num;
    Fraction temp(num, denom);

    numer = temp.numer;
    denom = temp.denom;
}

void Fraction::setDenom(int den)
{   
    Fraction temp(numer, den);

    numer = temp.numer;
    denom = temp.denom;
}