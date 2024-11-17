#include "Set.h"
#include <iostream>
#include <string>

Set::Set()
{
    capacity = 10;
    cnt = 0;
    data = new int[capacity];
}

Set::~Set()
{
    delete []data;
}

void Set::addData(int ent)
{   
    *(data+cnt++) = ent;

    if ( cnt >= capacity-1 )
    {
        capacity *= 2;
        int *temp = new int[capacity]; 
        for ( int i = 0; i < cnt; i ++ )
        {
            *(temp+i) = *(data+i);
        }
        delete []data; 
        data = temp;
    }
}

const int Set::get_capacity()
{
    return capacity;
}

const int Set::get_cnt()
{
    return cnt;
}

int* Set::get_data()
{
    return data;
}

void Set::duplicateDelete()
{      
    for ( int i = 0; i < cnt; i ++ )
    {   
        for ( int j = i+1; j < cnt; j ++ )
        {   
            if ( *(data+i) == *(data+j) )
                *(data+i) = 0;
        }
    }
    for ( int i = 0; i < cnt; i ++ )
    {
        if ( *(data+i) == 0 ) 
        {   
            for ( int j = 0; j < cnt-1; j ++ )
            {
                *(data+i+j) = *(data+i+j+1);
            }
            *(data + cnt - 1)= 0;
            cnt --;
            i --;
        }
    }
}

const Set Set::operator |(const Set& s1) const
{
    Set res;
    for ( int i = 0; i < cnt; i ++ )
        res.addData(*(data+i));

    for ( int i = 0; i < s1.cnt; i ++ )
        res.addData(*(s1.data+i));

    res.duplicateDelete();

    return res;
}

const Set Set::operator &(const Set& s1) const
{
    Set res;
    
    for ( int i = 0; i < cnt; i ++ )
    {
        for ( int j = 0; j < s1.cnt; j ++ )
        {
            if ( *(data+i) == *(s1.data+j) ) 
                res.addData(*(data+i));
        }
    }

    return res;
}

void Set::operator =(const Set& s1)
{
    this->capacity = s1.capacity;
    this->cnt = s1.cnt;
    for ( int i = 0; i < cnt; i ++ )
        *((this->data)+i) = *(s1.data+i);
}

istream& operator >>(istream& Istream, Set& s1)
{  
    int ent;
    Istream >> ent;
    while ( ent > 0 )
    {   
        s1.addData(ent);
        Istream >> ent;
    }
    s1.duplicateDelete();

    return Istream;
}

ostream& operator <<(ostream& Ostream, Set& s1)
{
    int *data = s1.get_data();
    for ( int i = 0; i < s1.get_cnt(); i ++ )
        Ostream << *(data+i) << " ";
    Ostream << endl;

    return Ostream;
}