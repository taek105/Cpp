#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int enter;
    int n;
    int cnt = 0;
    srand(time(NULL));

    n = rand()%101;

    cout << n << endl;

    while ( n != enter ) {
        cout << "guess n : ";
        cin >> enter;

        if (enter > n) 
        {
            cout << enter << " is bigger than n";
        }
        else 
        {
            cout << enter << " is less than n";
        }
        cnt ++;
    }
    cout << "\ngood! u got it in " << cnt << " times";
}