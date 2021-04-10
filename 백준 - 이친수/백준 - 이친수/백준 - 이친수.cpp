#include <iostream>
#include <memory.h>
using namespace std;
long long cache[91][2];
long long dp(int previous, int remain)
{
    if (remain == 0)
        return 1;

    long long& result = cache[remain][previous];
    if (result != 0) return result;

    if (previous == 1)
    {
        result += dp(0, remain - 1);
    }
    else
    {
        result += dp(1, remain - 1);
        result += dp(0, remain - 1);
    }    

    return result;
}
long long solution(int n)
{
    return dp(1, n - 1);
}
int main()
{
    int N = 0;
    cin >> N;
    memset(cache, 0, sizeof(cache));
    printf("%lld", solution(N));
}