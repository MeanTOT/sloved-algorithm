#include <iostream>
#include <memory.h>
using namespace std;
const int MOD = 10007;
int K = 0, N = 0;
int Answer = 0;
int cache[1001][1001];
int Dp(int index, int remain)
{
    int& ret = cache[index][remain];
    if (ret != -1) return ret % MOD;

    if (remain == 0)
    {
        return 1;
    }
    if (index == N)
    {
        return 0;
    }

    ret = (Dp(index + 1, remain - 1) + Dp(index + 1, remain)) % MOD;
    return ret % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));
    cout << Dp(0, K) % MOD;
}