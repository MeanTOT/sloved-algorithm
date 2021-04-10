#include <iostream>
#include <memory.h>
using namespace std;
long long cache[91];
long long dp(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long& result = cache[n];
    if (result != -1) return result;

    return result = dp(n - 1) + dp(n - 2);
}
int solution(int n)
{
    return dp(n);
}
int main()
{
    int N = 0;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    printf("%lld", dp(N));
}