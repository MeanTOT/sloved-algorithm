#include <iostream>
#include <memory.h>
using namespace std;
long long F[101];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 0;
    cin >> T;
    memset(F, 0, sizeof(F));
    F[1] = 1;
    F[2] = 1;
    F[3] = 1;
    for (int i = 4; i < 101; ++i)
    {
        F[i] = F[i - 3] + F[i - 2];
    }

    while (T--)
    {
        int N = 0;
        cin >> N;
        cout << F[N] << "\n";
    }
}