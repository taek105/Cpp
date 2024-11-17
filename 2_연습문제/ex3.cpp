#include <iostream>

using namespace std;

void showDigit (int enter)
{
        if ( enter > 0)
    {
        showDigit(enter / 10);
        cout << enter % 10 << " ";
    }
}
void showRDigit (int enter)
{
    if ( enter > 0)
    {
        cout << enter % 10 << " ";
        showRDigit(enter / 10);
    }
}


int main()
{
    int enter;

    cout << "insert integer (ends 0) : ";
    cin >> enter;

    while ( enter != 0 )
    {   
        cout << "Forward : ";
        showDigit(enter);
        cout << endl;
        cout << "Backward : ";
        showRDigit(enter);

        cout << "\ninsert integer (ends 0) : ";
        cin >> enter;
    }
    cout << "== END ==";
}