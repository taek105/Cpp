#include <iostream> 
#include <iomanip>
#include "Matrix.h"

using namespace std;

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