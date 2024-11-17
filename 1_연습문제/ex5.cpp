#include <iostream>

using namespace std;

int main()
{
    int enter;
    int temp = 0;
    
    cout << "입력 : ";
    cin >> enter;

    for (int i = 6; i <= enter; i++) //2부터 완전수체크 for문
    {
        for (int j = 1; j < i; j++) //역수합구하기 for문
        {
            if (i % j == 0)
            {
                temp = temp + j;
            }
        }
        if (i == temp) //완전수체크해서 출력
        {
            cout << i << "(";
            for (int j = 1; j < i; j++) //약수 다시찾기
            {
                if (i % j == 0) // 약수면 바로출력
                {
                    cout << j;
                    if (i/2 != j) cout << "+"; // 마지막 약수가 아니면 + 출력
                }
            }
            cout << ")" << endl;
        }
        temp = 0;
    }
}