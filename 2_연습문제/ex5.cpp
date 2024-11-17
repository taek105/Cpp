#include <iostream>

using namespace std;

void enterArray(int arr[], bool &check)
{   
    cout << "Enter 5 non-descending integer : ";
    cin >> arr[0];
    for ( int i = 1; i < 5; i ++ )
    {
        cin >> arr[i];
        if ( arr[i-1] > arr[i] ) check = true;
    }   
}
void mergeArrays(int arr1[], int arr2[], int length1, int length2, int res[])
{
    int p = 0, q = 0, i = 0;
 
    while (p < length1 && q <length2)
    {
        if (arr1[p] < arr2[q])
        {
            res[i] = arr1[p];
            i ++;
            p ++;
        }
        else
        {
            res[i] = arr2[q];
            i ++;
            q ++;
        }
    }

    while (p < length1)
    {
        res[i] = arr1[p];
        i ++;
        p ++;
    }

    while (q < length2)
    {
        res[i] = arr2[q];
        i ++;
        q ++;
    }
}
int main()
{   
    int a[5];
    int b[5];
    int res[10];
    bool descheck = false;

    enterArray(a, descheck);

    while (!descheck)
    {
        enterArray(b, descheck); if ( descheck ) break;

        mergeArrays(a, b, 5, 5, res);

        for ( int i = 0; i < 10; i ++ )
        {
            cout << res[i] << " ";
        }
        cout << endl;
        enterArray(a, descheck);
    }
    cout << "== END with non-descending order ==";
}
