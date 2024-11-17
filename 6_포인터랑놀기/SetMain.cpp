#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Set s1, s2, resultSet ;
    cout << "Input 2 sets of integers(Each set should end with a negative value)." << endl ; 
    cin >> s1 >> s2; 
    resultSet = s1 | s2;
    cout << "Union is " << resultSet ; // 합집합
    resultSet = s1 & s2 ;
    cout << "Intersection is " << resultSet ; // 교집합
}