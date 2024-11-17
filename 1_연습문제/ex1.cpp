#include <iostream>
using namespace std;

int main()
{
    double enter;
    int it;
    double pt;

    
    while ( enter != 0 )
    {
    cout << "부동소수점 값을 입력하세요(0에서 종료) : ";
    cin >> enter;

    it = (int) enter;
    // cout << it << endl;
    pt = enter - it;
    // cout << pt << endl;

    cout << "정수부 : " << it;
    cout << " 소수부 : " << pt << endl;
    }
}