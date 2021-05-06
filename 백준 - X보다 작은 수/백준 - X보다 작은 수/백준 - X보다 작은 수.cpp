#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, X = 0;
    cin >> N >> X;
    for (int i = 0; i < N; ++i)
    {
        int Num = 0;
        cin >> Num;
        if (Num < X) cout << Num << " ";
    }
}