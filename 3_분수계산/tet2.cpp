#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
private:
    const static int ROW = 3;
    const static int COL = 3;
    int mat[ROW][COL];
    int maxcol[COL] = {0, };

public:
    Matrix();
    void read();
    Matrix add(Matrix m);
    Matrix multi(Matrix m);
    void cntMaxcol(int[], int length);
    void print();
};


Matrix::Matrix(){}
void Matrix::read()
{   
    cout << "input : ";
    for ( int i = 0; i < ROW; i ++ )
    {
        for ( int j = 0; j < COL; j ++ )
        {
            cin >> mat[i][j];
            if ( abs(mat[i][j]) > maxcol[j] ) maxcol[j] = abs(mat[i][j]);
        }
    }
    cntMaxcol(maxcol, COL);
}
Matrix Matrix::add(Matrix m)
{   
    Matrix res;

    for ( int i = 0; i < ROW; i ++ )
    {
        for ( int j = 0; j < COL; j ++ )
        {
            res.mat[i][j] = mat[i][j] + m.mat[i][j];
            if ( abs(res.mat[i][j]) > res.maxcol[j] ) res.maxcol[j] = abs(res.mat[i][j]);
        }
    }
    cntMaxcol(res.maxcol, COL);
    return res;
}
Matrix Matrix::multi(Matrix m)
{   
    Matrix res;

    int temp;
    for ( int i = 0; i < ROW; i ++ )
    {
        for ( int j = 0; j < COL; j ++ )
        {
            temp = 0;
            for ( int k = 0; k < COL; k ++ )
            {  
                temp += mat[i][k] * m.mat[k][j];
            }
            res.mat[i][j] = temp;
            if ( abs(res.mat[i][j]) > res.maxcol[j] ) res.maxcol[j] = abs(res.mat[i][j]);
        }
    }
    cntMaxcol(res.maxcol, COL);
    return res;
}
void Matrix::cntMaxcol(int maxcol[], int length)
{   
    int maxcolLength = 0; 

    for ( int i = 0; i < length; i ++ )
    {
        while ( maxcol[i] > 0 )
        {
            maxcol[i] = maxcol[i] / 10;
            maxcolLength ++;
        }
        maxcol[i] = maxcolLength;
        maxcolLength = 0;
    }
}
void Matrix::print()
{   
    for ( int i = 0; i < COL; i ++ ) cout << maxcol[i];
    cout << endl;
    for ( int i = 0; i < ROW; i ++ )
    {   
        cout << "|";
        for ( int j = 0; j < COL; j ++ )
        {
            cout << setw(maxcol[j] + 2) << mat[i][j];
        }
        cout << " |" << endl;
    }
}


int main() 
{
    Matrix m1, m2 ;

    m1.read() ; m1.print () ; 
    m2.read() ; m2.print() ;

    Matrix m3 = m1.add(m2);
    cout << "Matrix ADD " << endl;
    m3.print() ;

    m3 = m1.multi(m2) ;
    cout << "Matrix Multiplication " << endl; 
    m3.print() ;
    return 0 ;
}