#include <iostream>
using namespace std;

int main() 
{
    int enter ;
    // int enter2 = 0;

    while ( enter != 0)
    {
        cout << "정수 값을 입력하세요(0에서 종료) : ";
        cin >> enter;

        while ( enter/10 != 0 )
            {cout << enter << endl;
            enter = enter / 10;}

        // enter2 = (int)enter;

        cout << "제일 큰 자리수 : " << enter <<endl;
    }

}