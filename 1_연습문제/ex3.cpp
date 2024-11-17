#include <iostream>
using namespace std;

int main() 
{
    int ent1 = 0;
    int ent2 = 0;
    int h;
    
    cout << "윗변과 밑변의 크기 : ";
    cin >> ent1 >> ent2;
    
    while ( ent1 != 0 ) 
    {
        if ( ent1 > ent2 )
        {
            int temp = ent1;
            ent1 = ent2;
            ent2 = temp;
        }
        if ( ent1 % 2 != ent2 % 2) 
        {
            cout << "두 값이 모두 짝수거나 홀수여야함" << endl;
        }
        else 
        {
            int nstar = ent1;
            h = (ent2 - ent1)/2 + 1;
            for ( int i = h; i > 0; i-- )
            {
                for ( int j = 0; j < h-1 ;  j++ ) 
                {
                    cout << " ";
                }
                for ( int q = 0; q < nstar; q++ ) 
                {
                    cout << "*";
                }
                nstar = nstar + 2;
                h = h-1;
                cout << endl;
            }
        }
        ent1 = 0, ent2 = 0;
        cout << "윗변과 밑변의 크기 : ";
        cin >> ent1 >> ent2;
    }
    cout << "종료합니다.";
}