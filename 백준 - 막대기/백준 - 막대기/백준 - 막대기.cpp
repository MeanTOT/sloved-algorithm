#include <iostream>
using namespace std;
int main()
{
    int X = 0;
    int result = 0;
    cin >> X;
    for (int i = 0; i < 7; i++)
    {
        if (X % 2 == 1) result++;
        X >>= 1;
    }
    cout << result;
}