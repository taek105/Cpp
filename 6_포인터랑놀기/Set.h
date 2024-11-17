#pragma once
#include <iostream>
#include <string>

using namespace std;

class Set
{
private:
    int capacity;
    int cnt;
    int *data;
   
public:
    Set();
    ~Set();
    void addData(int);
    const int get_capacity();
    const int get_cnt();
    int* get_data();
    void duplicateDelete();
    const Set operator |(const Set& s1) const;
    const Set operator &(const Set& s1) const;
    void operator =(const Set& s1);
};
istream& operator >>(istream& Istream, Set& s1);
ostream& operator <<(ostream& Ostream, Set& s1);