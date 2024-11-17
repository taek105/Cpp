#include <iostream>

using namespace std;

class Money
{
private:
    int dollars;
    int cents;

public:
    Money();
    Money(int dol, int cent);

    const Money operator +(const Money& secM) const;
    const Money operator -(const Money& secM) const;
    bool operator ==(const Money& secM) const;
    bool operator !=(const Money& secM) const;
    bool operator >=(const Money& secM) const;
    bool operator <=(const Money& secM) const;
    bool operator >(const Money& secM) const;
    bool operator <(const Money& secM) const;

    void input();
    const string toString() const;
    
};

Money::Money(){}
Money::Money(int dol, int cen)
{   
    if ( cen >= 100 )
    {
        dol = dol + (cen / 100); 
        cen = cen % 100;
    }

    dollars = dol;
    cents = cen;
}
const Money Money::operator +(const Money& secM) const
{   
    return Money(dollars + secM.dollars, cents + secM.cents);
}
const Money Money::operator -(const Money& secM) const
{   
    int resCents;
    int cnt = 0;

    resCents = cents - secM.cents;
    if ( resCents < 0 )
    {
        cnt ++;
        resCents = resCents + 100;
    }

    return Money(dollars - secM.dollars - cnt, resCents);
}
bool Money::operator ==(const Money& secM) const
{
    return ((dollars == secM.dollars) && (cents == secM.cents));
}
bool Money::operator !=(const Money& secM) const
{
    return ((dollars != secM.dollars) || (cents != secM.cents));
}
bool Money::operator >=(const Money& secM) const
{
    return ( (dollars > secM.dollars) ||  
    ((dollars == secM.dollars) && (cents >= secM.cents)) );
}
bool Money::operator <=(const Money& secM) const
{
    return ( (dollars < secM.dollars) ||  
    ((dollars == secM.dollars) && (cents <= secM.cents)) );
}
bool Money::operator >(const Money& secM) const
{
    return ( (dollars > secM.dollars) ||  
    ((dollars == secM.dollars) && (cents > secM.cents)) );
}
bool Money::operator <(const Money& secM) const
{
    return ( (dollars < secM.dollars) ||  
    ((dollars == secM.dollars) && (cents < secM.cents)) );
}
void Money::input()
{
    int dol, cen;

    cout << "Input dollars and cents : ";
    cin >> dol >> cen;

    if ( cen >= 100 )
    {
        dol = dol + (cen / 100); 
        cen = cen % 100;
    }
    dollars = dol; cents = cen;

}
const string Money::toString() const
{
    if ( cents >= 10 )
    return "$" + to_string(dollars) + "." + to_string(cents);

    else 
    return "$" + to_string(dollars) + ".0" + to_string(cents);
}

int main()
{
    Money m1, m2, END_AMOUNT(0, 0);

    m1.input();

    while ( m1 != END_AMOUNT )
    {
        cout << "Input amount is : "<< m1.toString() << endl;
        
        m2.input();
        cout << "Input amount is : "<< m2.toString() << endl;

        cout << m1.toString() << " + " << m2.toString() << " = " 
        << (m1 + m2).toString() << endl;
        cout << m1.toString() << " - " << m2.toString() << " = " 
        << (m1 - m2).toString() << endl;

        cout << m1.toString() << " == " << m2.toString() << " is ";
        if ( m1 == m2 ) cout << "true\n";
        else cout << "false\n";
        cout << m1.toString() << " >= " << m2.toString() << " is ";
        if ( m1 >= m2 ) cout << "true\n";
        else cout << "false\n";
        cout << m1.toString() << " <= " << m2.toString() << " is ";
        if ( m1 <= m2 ) cout << "true\n";
        else cout << "false\n";
        cout << m1.toString() << " > " << m2.toString() << " is ";
        if ( m1 > m2 ) cout << "true\n";
        else cout << "false\n";
        cout << m1.toString() << " < " << m2.toString() << " is ";
        if ( m1 < m2 ) cout << "true\n";
        else cout << "false\n";

        m1.input(); 
    }
    cout << "Stop with 0d 0c";
}