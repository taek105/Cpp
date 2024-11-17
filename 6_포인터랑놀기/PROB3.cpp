#include <iostream>

using namespace std;

void print2DArr(int (*p)[3], int size)
{
    for (int i = 0 ; i < size ; i ++)
    {
        for (int j = 0 ; j < size ; j ++)
            cout << p[i][j] << " " ; 
        cout << endl ;
    }
    cout << endl ; 
}
void print2DArr2(int *p[], int size)
{
    for ( int i = 0 ; i < size ; i ++)
    {
        for ( int j = 0; j < size; j ++ )
            cout << *(p[i] + j) << " " ;
        cout << endl ;
    }
    cout << endl ; 
}

void print2DArr3(int *p, int size)
{
    for ( int i = 0 ; i < size ; i ++)
    {
        for ( int j = 0 ; j < size ; j ++ )
            cout << *(p + i*size + j) << " " ;
        cout << endl ;
    }
    cout << endl ; 
}

int main()
{
    // 함수의 인자 **p는 포인터의 주소값을 받는 것인데 arr은 배열 안에 배열이 있으므로 **로 받으면 
    // 입력받은 인자가 2차원 배열인지 단순한 주소인지 몰라서 배열에 대한 연산에서 컴파일 오류

    const int MAX = 3 ;
    int arr[MAX][MAX] = {1,2,3,4,5,6,7,8,9}; 
    print2DArr(arr, MAX); 
    // 함수 인자를 (*p)[]로 바꿔서 출력

    int row1[MAX] = {1, 2, 3};
    int *arr2_0 = row1;
    int row2[MAX] = {4, 5, 6};
    int *arr2_1 = row2;
    int row3[MAX] = {7, 8, 9};
    int *arr2_2 = row3;
    int *arr2[3] = {arr2_0, arr2_1, arr2_2}; 
    print2DArr2(arr2, MAX); 
    // 함수 인자를 포인터의 배열로 바꿔서 전달

    print2DArr3((int*)arr, MAX); 
    // 함수 인자를 1차원 int*형으로 타입 변환해서 전달

    return 0 ;
}