#include <iostream>

using namespace std;

int nfaciteration (int enter)
{
    int res = 1;

    while ( enter != 0 ) 
    {
        res = res * enter;

        enter --;
    }

    return res;
}
int nfacrecursive (int enter)
{
    int res;

    if ( enter > 1 ) res = enter * nfacrecursive(enter - 1);
    else return 1;
    
    return res;
}


int main()
{
    int enter;

    cout << "insert integer(ends 0) : ";
    cin >> enter;

    while ( enter != 0 )
    {
        cout << "res use iteration : " << nfaciteration(enter) << endl;
        cout << "res use recursion : " << nfacrecursive(enter) << endl;

        cout << "insert integer(ends 0) : ";
        cin >> enter;
    } 
    cout << "== END ==";
}
