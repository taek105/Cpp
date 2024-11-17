#include <iostream>
#include <math.h>
#include "MyString.h"

using namespace std;

void MyString::resize()
{
    if ( leng == size )
    {
        size *= 2;
        char *temp = new char[size]; 

        for ( int i = 0; i < leng; i ++ )
            temp[i] = data[i];
        
        delete []data; 
        data = temp;
    }
}
void MyString::clear()
{
    delete []data;

    leng = 0;
    size = 8;
    data = new char[size];
}
void MyString::addData(char c)
{
    resize();
   
    (this->data)[leng++] = c;
}
void MyString::addDatas(const char* data)
{        
    int i = 0;
    
    while ( data[i] )
        this->addData(data[i++]);

}
void MyString::addDatas(const char *data, int cnt)
{        
    for ( int i = 0; i < cnt; i ++ )
    {
        if ( data[i] == '\0' ) break;
        this->addData(data[i]);
    }
}
const int MyString::compare(const char *str2nd) const
{
    // -1:내가less 0:equal 1:bigger
    int str2ndLeng = 0;
    while ( str2nd[str2ndLeng] )
        str2ndLeng++;
    str2ndLeng++;

    int res = 0;
    int i = 0;
    while ( this->data[i] && str2nd[i] )
    {
        if ( (int)this->data[i] > (int)str2nd[i] )
        {
            res = 1;
            break;
        }
        else if ( (int)this->data[i] < (int)str2nd[i] )
        {
            res = -1;
            break;
        }
        else
            i ++;
    }

    if ( res == 0 )
    {
        if ( this->leng > str2ndLeng )
            res = 1;
        else if ( this->leng == str2ndLeng )
            res = 0;
        else 
            res = -1;
    }

    return res;
}
const char* MyString::getData() const
{
    return this->data;
}
istream& MyString::read(istream& is)
{   
    this->clear();

    char enter = is.get();
    while ( isspace(enter) )
        enter = is.get();
    
    while ( !isspace(enter) )
    {   
        this->addData(enter);
        
        enter = is.get();
    }
    is.unget();
    this->addData('\0');

    return is;
}
istream& MyString::read(istream& is, char delim)
{   
    this->clear();

    char enter = is.get();
    while ( enter != delim )
    {   
        this->addData(enter);
        
        enter = is.get();
    }
    is.unget();
    this->addData('\0');

    return is;
}

//난이도 하
MyString::MyString()
{
    leng = 1;
    size = 8;
    data = new char[size];
    data[0] = '\0';
}
MyString::MyString(const MyString& srcStr)
{
    this->size = srcStr.size;
    this->leng = srcStr.leng;
    for ( int i = 0; i < leng; i ++ )
        (this->data)[i] = (srcStr.data)[i];

    cout << "copy occured\n";
}
MyString::MyString(const char *str2nd)
{
    leng = 0;
    size = 8;
    data = new char[size];
    
    this->addDatas(str2nd);
    this->addData('\0');

    cout << "copy occured\n";
}
const MyString& MyString::operator =(const MyString& srcStr)
{   
    if ( *this == srcStr )
            return *this;
    else 
        return (*this=srcStr.data);
}
const MyString& MyString::operator =(const char *str2nd)
{
    this->clear();
    
    this->addDatas(str2nd);
    this->addData('\0');

    return *this;
}
MyString::~MyString()
{
    delete []data;
    cout << "Delete occured\n";
}
const int MyString::length() const
{
    return leng-1;
}
const bool MyString::empty() const
{
    bool res = 0;
    if ( this->data[0] == 'n' )
        res = 1;

    return res;
}
const char MyString::at(int pos) const
{
    return this->data[pos];
}
const char MyString::operator[](int pos) const
{   
    return this->data[pos];
}
//난이도 중

MyString MyString::operator +(const char *str2nd) const
{
    MyString res;
    res.clear();
    
    res.addDatas(this->data);
    res.addDatas(str2nd);
    res.addData('\0');

    return res;
}
MyString MyString::operator +(const MyString& str2nd) const
{
    return *this + str2nd.data;
}
const bool MyString::operator ==(const MyString& str2nd) const
{
    bool res = 1;

    if ( leng != str2nd.leng )
        res = 0;
    else
    {
        for ( int i = 0; i < leng-1; i ++ )
        {
            if ( data[i] != str2nd.data[i] )
            {
                res = 0;
                break;
            }
        }
    }

    return res;
}
const bool MyString::operator !=(const MyString& str2nd) const
{
    return !((*this) == str2nd);
}
const int MyString::find(const char *subStr) const
{
    return find(0, subStr);
}
const int MyString::find(const MyString& subStr) const
{
    return find(0, subStr.data);
}
const int MyString::find(int pos, const char *subStr) const
{
    // int res = pos;

    // while ( data[res] && data[res] != subStr[0] )
    //     res ++;

    // if ( res == leng-1 )
    //     res = -1;
    // else 
    // {
    //     int i = 0;
    //     int j = res;
    //     while ( subStr[i] )
    //     {
    //         if ( data[j] != subStr[i] )
    //         {
    //             res = -1;
    //             break;
    //         }
    //         i ++;
    //         j ++;
    //     }
    // }
    
    // return res;

    int sizeSubStr = 0;
    while ( subStr[sizeSubStr] )
        sizeSubStr++;

    int cnt = 0;

    for ( int i = pos; i < size; i ++ )
    {
        if ( data[i] == subStr[cnt] )
        {
            cnt ++;
            if ( cnt >= sizeSubStr )
                return i - sizeSubStr + 1;
        }
        else
            cnt = 0;
    }

    return -1;
}
const int MyString::find(int pos, const MyString& subStr) const
{
    return find(pos, subStr.data);
}
MyString MyString::substr(int pos, int cnt) const
{
    MyString res;
    res.clear();

    res.addDatas(&(this->data[pos]), cnt);
    res.addData('\0');

    return res;
}
//난이도 중상

const MyString& MyString::operator +=(const char* str2nd)
{
    this->leng --;

    this->addDatas(str2nd);
    this->addData('\0');

    return *this;
}
const MyString& MyString::append(const char *str2nd)
{
    return (*this+=str2nd);
}
const MyString& MyString::append(const MyString& str2nd)
{
    return (*this+=str2nd.data);
}
const bool MyString::operator <(const MyString& str2nd) const
{
    return *this<str2nd.data;
}
const bool MyString::operator <=(const MyString& str2nd) const
{
    return *this<=str2nd.data;
}
const bool MyString::operator >(const MyString& str2nd) const
{
    return *this>str2nd.data;
}
const bool MyString::operator >=(const MyString& str2nd) const
{
    return *this>=str2nd.data;
}
const bool MyString::operator <(const char *str2nd) const
{
    bool res = 1;
    int temp = this->compare(str2nd);

    if ( temp > -1 )
        res = 0;

    return res;
}
const bool MyString::operator <=(const char *str2nd) const
{
    bool res = 1;
    int temp = this->compare(str2nd);

    if ( temp > 0 )
        res = 0;

    return res;
}
const bool MyString::operator >(const char *str2nd) const
{
    bool res = 1;
    int temp = this->compare(str2nd);

    if ( temp < 1 )
        res = 0;

    return res;
}
const bool MyString::operator >=(const char *str2nd) const
{
    bool res = 1;
    int temp = this->compare(str2nd);

    if ( temp < 0 )
        res = 0;

    return res;
}
void MyString::insert(int pos, const char *subStr)
{   
    this->replace(pos, 0, subStr);
}
void MyString::insert(int pos, const MyString& subStr)
{
    this->replace(pos, 0, subStr.data);
}
void MyString::replace(int pos, int cnt, const char *subStr)
{
    MyString temp;
    temp.clear();

    temp.addDatas(this->data, pos);
    temp.addDatas(subStr);
    temp.addDatas(&(this->data[pos+cnt]));
    temp.addData('\0');

    *this = temp;
}
void MyString::replace(int pos, int cnt, const MyString& subStr)
{
    this->replace(pos, cnt, subStr.data);
}
void MyString::remove(int pos, int cnt)
{
    char n = '\0';
    this->replace(pos, cnt, &(n));
}
//난이도 하

ostream& operator <<(ostream& os, MyString &str)
{
    for ( int i = 0; i < str.length()+1; i ++ )
        os << str.getData()[i];

    os << " / " << str.length()+1 << endl;

    return os;
}
// cin >> str1 >> str2 ;
istream& operator >>(istream& is, MyString &str)
{
    return str.read(is);
}
istream& getline(istream& is, MyString& str)
{
    return str.read(is, '\n');
}
istream& getline(istream& is, MyString& str, char delim)
{
    return str.read(is, delim);
}
//난이도 중상

int stoi(const MyString& str, int pos, int base)
{
    int res = 0;
    int count = 0;
    int* supportArray = new int[str.length()+1];
    supportArray[0] = 0;
    const char* data = str.getData();
    
    if ( 1 < base && base < 11)
    {    
        for ( int i = pos; i < str.length(); i ++ )
        {
            if ( '0' <= (int)data[i] && (int)data[i] <= '0'+base-1 )
                supportArray[count++] = (int)data[i]-'0';
            
            else if ( supportArray[0] != 0 )
                break;
        }
    }
    else if ( 10 < base && base < 17 )
    {
        for ( int i = pos; i < str.length(); i ++ )
        {
            if ( '0' <= (int)data[i] && (int)data[i] <= '9' )
                supportArray[count++] = (int)data[i]-'0'; 

            else if ( 'a' <= (int)data[i] && (int)data[i] <= 'a'+base-11 )
                supportArray[count++] = (int)data[i]-'a'+10; 

            else if ( 'A' <= (int)data[i] && (int)data[i] <= 'A'+base-11 )
                supportArray[count++] = (int)data[i]-'A'+10; 

            else if ( supportArray[0] != 0 )
                break;
        }
    }

    for ( int i = count-1, j = 0; i >= 0; i --, j++ )
    {
        res += supportArray[i]*pow(base,j);
    }

    delete []supportArray;

    if ( count == 0 )
        return -1;
    else
        return res;
}