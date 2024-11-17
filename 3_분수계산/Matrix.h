#pragma once

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