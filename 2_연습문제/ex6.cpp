#include <iostream>
#include <iomanip>

using namespace std;

const int ROW = 3;
const int COL = 3;

void print(int row, int col, int res[][COL])
{   
    for ( int i = 0; i < row; i ++ )
    {   
        cout << "|";
        for ( int j = 0; j < col; j ++ )
        {
            cout << setw(3) << res[i][j];
        }
        cout << " |" << endl;
    }
}
void transpose(int a[][COL], int row, int col, int res[][COL])
{   
    for ( int i = 0; i < row; i ++ )
    {
        for ( int j = 0; j < col; j ++ )
        {
            res[i][j] = a[j][i];
        }
    }
}
void sum(int a[][COL], int b[][COL], int row, int col, int res[][COL])
{
    for ( int i = 0; i < row; i ++ )
    {
        for ( int j = 0; j < col; j ++ )
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}
void multiplcation(int a[][COL], int b[][COL], int row, int col, int res[][COL])
{
    int temp;
    for ( int i = 0; i < row; i ++ )
    {
        for ( int j = 0; j < col; j ++ )
        {
            temp = 0;
            for ( int k = 0; k < col; k ++ )
            {  
                temp += a[i][k] * b[k][j];
            }
            res[i][j] = temp;
        }
    }
}
int main()
{
    int res[ROW][COL] = {0, };

    int a[ROW][COL] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int b[ROW][COL] =
    {
        {1, -1, 0},
        {0, -1, 1},
        {-1, 1, 0}
    };
    cout << "Transpose" << endl << endl;
    transpose(a, ROW, COL, res);
    print(ROW, COL, res);

    cout << "Sum" << endl << endl;
    sum(a, b, ROW, COL, res);
    print(ROW, COL, res);

    cout << "Multiplcation\n\n";
    multiplcation(a, b, ROW, COL, res);
    print(ROW, COL, res);
}
