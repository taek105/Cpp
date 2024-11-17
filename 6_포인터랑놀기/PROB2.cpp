#include <iostream>

using namespace std;

void print1DArr(int *enter, int length)
{
    for ( int i = 0; i < length; i ++ )
        cout << *( enter + i ) << " ";
    cout << endl;
}

int main() 
{
    const int MAX = 5 ;
    int arr1[MAX] = {1,2,3,4,5}, arr2[MAX], *p ;
    // arr2 = arr1 ;  
    // 배열은 대입이 안 되고 값을 복사해주려면 일일이 초기화 해줘야 함
    for ( int i = 0; i < MAX; i ++ )
        arr2[i] = arr1[i];
    // p = arr1 ; 
    // 수정 전은 p가 arr1을 가리키는 것이고, 
    // arr1의 복사본을 가지려면 일일히 초기화 해줘야 함
    p = new int[MAX];
    for ( int i = 0; i < MAX; i ++ )
        *(p+i) = arr1[i];
    p[0] = 99 ;

    print1DArr(arr1, MAX) ;
    print1DArr(arr2, MAX) ;
    print1DArr(p, MAX) ;

    return 0 ;
}