#include <iostream>

using namespace std;

class Fraction
{
private:
    int numer;
    int denom;
    const int pmCheck();
    void reduce();

public:
    Fraction();
    Fraction(int num, int dem);
    void setNumer(int den);
    void setDenom(int num);
    const Fraction operator +(const Fraction& f1) const;
    friend ostream& operator <<(ostream& outputStream, const Fraction& f1);
};
int getGCD(int a, int b);

int getGCD(int a, int b)
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

const int Fraction::pmCheck()
{
    int pmcnt = 0;
    
    if ( numer < 0 ) 
    {
        pmcnt ++; 
        numer = -numer;
    }
    if ( denom < 0 ) 
    {
        pmcnt ++; 
        denom = -denom;
    }

    return pmcnt;
}

void Fraction::reduce()
{
    int gcd = getGCD(numer, denom);
    
    numer = numer / gcd;
    denom = denom / gcd;
}

Fraction::Fraction()
{
    numer = 1;
    denom = 1;
}

Fraction::Fraction(int num, int den)
{   
    if ( den == 0 ) 
    {
        cout << "분모를 1로 바꿈 \n";
        den = 1;
    }
    
    numer = num;
    denom = den;
    int pmcnt = pmCheck();

    reduce();

    if ( pmcnt % 2 == 1 ) numer = -numer;
}

void Fraction::setNumer(int num)
{   
    if ( numer < 0 ) num = -num;

    numer = num;
    int pmcnt = pmCheck();

    reduce();

    if ( pmcnt % 2 == 1 ) numer = -numer;
}

void Fraction::setDenom(int den)
{   
    if ( den == 0 ) 
    {
        cout << "분모를 1로 바꿈 \n";
        den = 1;
    }
    
    denom = den;
    int pmcnt = pmCheck();

    reduce();

    if ( pmcnt % 2 == 1 ) numer = -numer;
}

const Fraction Fraction::operator +(const Fraction& f2) const
{   
    Fraction res(numer * f2.denom + f2.numer * denom, denom * f2.denom);
    
    return res;
}

ostream& operator <<(ostream& outputStream, const Fraction& f1)
{   
    if ( f1.numer == 0 ) cout << 0;

    else outputStream << f1.numer << "/" << f1.denom;   

    return outputStream;
}

int main() 
{
    Fraction f1(2,3), f2(2, -5), f3 ;

    f3 = f1 + f2;

    cout << f1 << " + " << f2;
    cout << " = " << f3 <<endl;

    return 0;
}