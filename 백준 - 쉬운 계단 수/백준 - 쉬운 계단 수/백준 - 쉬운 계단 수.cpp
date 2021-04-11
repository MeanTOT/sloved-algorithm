#include <iostream>
#include <memory.h>
using namespace std;
int N = 0;
int const MOD = 1000000000;
long long cache[10][101];
long long dp(int number, int remain)
{
    if (remain == 0)
        return 1;

    long long& result = cache[number][remain];
    if (result != 0) return result;

    if (number == 0)
        result += dp(number + 1, remain - 1);
    else if (number == 9)
        result += dp(number - 1, remain - 1);
    else
    {
        result += dp(number + 1, remain - 1);
        result += dp(number - 1, remain - 1);
    }

    return result % MOD;
}
int solution()
{
    long long result = 0;
    for (int i = 1; i < 10; i++)
    {
        result += dp(i, N - 1);
    }

    return result % MOD;
}
int main()
{
    cin >> N;
    memset(cache, 0, sizeof(cache));
    printf("%lld", solution());
}