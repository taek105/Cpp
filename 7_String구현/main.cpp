#include <iostream>
// #include <Math.h>
#include "MyString.cpp"

using namespace std;

int main()
{
    MyString m1 = "aaabaa";

    cout << m1.find("aaab");
}