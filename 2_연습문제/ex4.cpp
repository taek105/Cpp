#include <iostream>

using namespace std;
    
int main()
{
    int enter = 0;
    int cnt = 0;
    bool res[32];
    bool evencheck = 0;

    cout << "insert decimal n(ends 0) : ";
    cin >> enter;
    
    while ( enter != 0 )
    {   
        while ( enter > 0 )
        {
            res[cnt] = enter % 2;
            enter = enter / 2;
            cnt ++;
        }
        for ( int i = cnt-1; i >= 0; i -- )
        {
            cout << res[i];
        }
        cout << endl;
        cnt = 0;
        cout << "insert decimal n(ends 0) : ";
        cin >> enter;
    }
    cout << "== END ==";
}