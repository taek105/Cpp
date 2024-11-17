#pragma once

#include <iostream>
#include <math.h>

using namespace std;

class MyString
{
private:
    char *data;
    int leng;
    int size;
    void resize();
    void clear();
    void addData(char c);
    void addDatas(const char*);
    void addDatas(const char*, int cnt);
    const int compare(const char* str2nd) const;

public:
    const char* getData() const;
    istream& read(istream& is);
    istream& read(istream& is, char delim);

    // 난이도 하
    MyString();
    MyString(const MyString& srcStr);
    MyString(const char *str2nd);
    const MyString& operator =(const MyString &srcStr);
    const MyString& operator =(const char *str2nd);
    ~MyString();
    const int length() const;
    const bool empty() const;
    const char at(int pos) const;
    const char operator [](int pos) const;
    // 난이도 중
    MyString operator +(const char *str2nd) const;
    MyString operator +(const MyString& str2nd) const;
    const bool operator ==(const MyString& str2nd) const;
    const bool operator !=(const MyString& str2nd) const;
    const int find(const char* subStr) const;
    const int find(const MyString& subStr) const;
    const int find(int pos, const char* subStr) const;
    const int find(int pos, const MyString& subStr) const;
    MyString substr(int pos, int cnt) const;
    // 난이도 중상
    const MyString& operator +=(const char *str2nd);
    const MyString& append(const char *str2nd);
    const MyString& append(const MyString& str2nd);
    const bool operator <(const MyString&) const;
    const bool operator <=(const MyString&) const;
    const bool operator >(const MyString&) const;
    const bool operator >=(const MyString&) const;
    const bool operator <(const char *) const;
    const bool operator <=(const char *) const;
    const bool operator >(const char *) const;
    const bool operator >=(const char *) const;
    void insert(int pos, const char *subStr);
    void insert(int pos, const MyString& subStr);
    void replace(int pos, int cnt, const char *subStr);
    void replace(int pos, int cnt, const MyString& subStr);
    void remove(int pos, int cnt);

};
// 난이도 하
ostream& operator <<(ostream& os, MyString &str);
istream& operator >>(istream& is, MyString &str);
istream& getline(istream& is, MyString& str);
istream& getline(istream& is, MyString& str, char delim);
// 난이도 중상
int stoi(const MyString& str, int pos = 0, int base = 10);