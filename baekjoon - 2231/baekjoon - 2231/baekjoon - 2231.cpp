#include <iostream>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;
    int constructer = N;
    int lastConstructer = 0;
    for (int i = 0; i < 54; ++i)
    {
        int temp = constructer;
        int sumTarget = 0;
        while (temp >= 10)
        {
            sumTarget += temp % 10;
            temp /= 10;
        }
        sumTarget += temp;
        if (sumTarget + constructer == N)
        {
            lastConstructer = constructer;
        }        
        constructer--;
        if (constructer == 0) break;
    }

    if (lastConstructer != 0) cout << lastConstructer;
    else cout << 0;
}