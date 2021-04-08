#include <iostream>
#include <memory.h>
using namespace std;
int cache[21];
int fibo(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int& result = cache[n];
    if (result != -1) return result;
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int N = 0;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    cout << fibo(N);
}
