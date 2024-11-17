#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int ent1;
    int ent2;
    int ent3;
    int temp = 1;

    cout << "몇단까지 출력할까요 : ";
    cin >> ent1;
    cout << "몇까지 곱할까요 : ";
    cin >> ent2;
    cout << "한줄에 몇단 출력할까요 : ";
    cin >> ent3;

    for ( int q = 0; q < (ent1/ent3); q ++)
    {
        for ( int i = 1; i < ent2 + 1 ; i++ )
        {
            for ( int j = temp; j < (temp + ent3); j++)
            {
                cout << setw(2) << j << " x " << setw(2) << i << " =" << setw(4) << i*j << "    ";
            }
            cout << endl;
        }
        cout << endl; 
        temp = temp + ent3;
        if ( temp > ent1 ) 
        {
            temp = temp - ent3;
        }
    }
    if ( ent1 % ent3 != 0)
    {
        for ( int i = 1; i < ent2 + 1 ; i++ )
        {
            for ( int j = temp; j <= ent1; j++)
            {
                cout << setw(2) << j << " x " << setw(2) << i << " =" << setw(4) << i*j << "    ";
            }
            cout << endl;
        }
    }
}