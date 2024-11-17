#include <iostream>

using namespace std;

class Dday
{
private:
    int year;
    int month;
    int day;
    int setDday;
    void monthPlus(int);
    void monthMinus(int);
    void setD();
    void setM();

public:
    Dday();
    Dday(int y, int m, int d, int sD);
    void printDday() const;
    Dday& operator ++();
    Dday& operator --();
    const Dday operator +(const int& d1);
    // const Dday operator -(const int& d1);
    const bool operator !=(const Dday&) const;
    friend istream& operator >>(istream& inputStream, Dday& d1);
    friend ostream& operator <<(ostream& outputStream, Dday d1);

};

void Dday::monthPlus(int dayCnt)
{
    day = day - dayCnt;
    month ++;
    setD();
}

void Dday::monthMinus(int dayCnt)
{
    day = day + dayCnt;
    month --;
    setD();
}

void Dday::setD()
{
    // static const int MAX_MONTH_DAYS[12] = {31,28,31,30....} ;
    if ( month == 1 )
    {
        if ( day > 31 )
            monthPlus(31);
        else if ( day < 1 )
        {
            day = day + 31;
            month = 12;
            year --;
            setD();
        }
    } 
    else if ( month == 2 )
    {
        if ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {   
            if ( day > 29 ) 
                monthPlus(29);
            else if ( day < 1 )
                monthMinus(31);
        }
        else 
        {
            if ( day > 28 )
                monthPlus(28);
            else if ( day < 1 )
                monthMinus(31);
        }

    }
    else if ( month == 3 )
    {   
        if ( day > 31 )
            monthPlus(31);
        else if ( day < 1 )
        {
            if ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                monthMinus(29);
            else 
                monthMinus(28);
        }
    }
    else if ( month == 5 || month == 7 || month == 10 )
    {
        if ( day > 31 )
            monthPlus(31); // monthPlus(MAX_MONTH_DAYS[month])
        else if ( day < 1 )
            monthMinus(30);
    }    
    else if (month == 8)
    {
        if ( day > 31 )
            monthPlus(31);
        else if ( day < 1 )
            monthMinus(31);
    }
    else if ( month == 12 )
    {
        if ( day > 31 )
        {
            day = day - 31;
            month = 1;
            year ++;
            setD();
        }
        else if ( day < 1 )
            monthMinus(30);
    }
    else 
    {
        if ( day > 30 )
            monthPlus(30);
        else if ( day < 1 )
            monthMinus(31);
    }
}

Dday::Dday()
{
    year = 2022;
    month = 10;
    day = 3;
    setDday = 0;
}

Dday::Dday(int y, int m, int d, int sD)
{
    year = y;
    month = m;
    day = d;
    setDday = sD;
}

void Dday::printDday() const
{
    if ( day < 10 )
    {
        if ( month < 10 )
            cout << year << "/0" << month << "/0" << day;
        else
            cout << year << "/" << month << "/0" << day;
    }
    else
    {
        if ( month < 10 )
            cout << year << "/0" << month << "/" << day;
        else
            cout << year << "/" << month << "/" << day;
    }
}

Dday& Dday::operator ++()
{   
    day = day + 1;
    setD();

    return *this;
}

Dday& Dday::operator --()
{
    day = day - 1;
    setD();

    return *this;
}

const Dday Dday::operator +(const int& plusday)
{
    day = day + plusday;
    setD();

    Dday res(year, month, day, setDday);
    return res;
}

// const Dday Dday::operator -(const int& minusday)
// {
//     day = day - minusday;
//     setD();

//     Dday res(year, month, day, setDday);
//     return res;
// }

const bool Dday::operator !=(const Dday& d1) const
{
    return ((year != d1.year) || (month != d1.month)  || (day != d1.day) || (setDday != d1.setDday));
}

istream& operator >>(istream& inputStream, Dday& d1)
{
    char enter[9] = {'\0', };
    cin >> enter;

    if ( enter[0] == '+' && enter[1] == '\0') 
    {
        ++d1;
    }
    else if ( enter[0] == '-' && enter[1] == '\0') --d1;
    else if ( enter[0] == '+') 
    {

        d1.setDday = stoi(enter)-1;
    }
    else if ( enter[0] == '-') d1.setDday = stoi(enter);
    else if ( enter[0] == 'Q' || enter[0] == 'q') 
    {
        d1.year = 0; d1.month = 0; d1.day = 0; d1.setDday = 0;
    }
    else
    {
        int y, m, d;
        bool err = 0;

        y = (enter[0]-'0') * 1000 + (enter[1]-'0')*100 + (enter[2]-'0') * 10 + (enter[3]-'0');
        m = (enter[4] - '0') * 10 + (enter[5]-'0');
        d = (enter[6]-'0') * 10 + (enter[7]-'0');

        if ( m > 12 ) 
        {
            cout << "*** WRONG MONTH!! TRY AGAIN ***\n";
            err = 1;
        }
        else if ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 )
        {
            if ( d > 31 )
            {
                cout << "*** WRONG DAY!! TRY AGAIN ***\n";
                err = 1;
            }
        }
        else if ( m == 4 || m == 6 || m == 9 || m == 11 )
        {
            if ( d > 30 )
            { 
                cout << "*** WRONG DAY! TRY AGAIN ***\n";
                err = 1;
            }
        }
        else if ( m == 2 )
        {
            if ( y % 4 == 0 && y % 100 != 0 || y % 400 == 0 )
            {
                if ( d > 29 )
                { 
                    cout << "*** WRONG DAY! TRY AGAIN ***\n";
                    err = 1;
                }
            }
            else
                if ( d > 28 )
                { 
                    cout << "*** WRONG DAY! TRY AGAIN ***\n";
                    err = 1;
                }
        }
        
        if ( !err )
        {
            d1.year = y; d1.month = m; d1.day = d;
            d1.setD();
        }
    }

    return inputStream;
}

ostream& operator <<(ostream& outputStream, Dday d1)
{  

    outputStream << "[Date] ";
    d1.printDday();
    
    outputStream << " [D-day] ";
    if ( d1.setDday == 0 )
    {
        outputStream << "NONE";
    }
    else
    {
        (d1 + d1.setDday).printDday();
    }
    outputStream << endl;

    return outputStream;
}



int main()
{
    Dday dday;
    Dday END_DDAY(0, 0, 0, 0);
    
    cout << dday;

    cout << "Move date(yyyymmdd, (tomorrow)+, (yesterday)-, set D-day(+/-int), Quit(Q/q)) : ";
    cin >> dday;

    while ( dday != END_DDAY )
    {
        cout << dday;
        
        cout << "Move date(yyyymmdd, (tomorrow)+, (yesterday)-, set D-day(+/-int), Quit(Q/q)) : ";
        cin >> dday;
    }

    cout << "=== END ===";
}