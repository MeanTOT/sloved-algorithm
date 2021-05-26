#include <iostream>
using namespace std;

int GetFactorial(int val)
{
    int ret = 1;
    for (int i = 1; i <= val; ++i)
    {
        ret *= i;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, K = 0;
    cin >> N >> K;
    cout << GetFactorial(N) / (GetFactorial(N - K) * GetFactorial(K));
}