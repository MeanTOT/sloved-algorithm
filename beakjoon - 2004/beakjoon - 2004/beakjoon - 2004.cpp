#include <iostream>
using namespace std;

int GetZeroCountWithFive(int val)
{
    int ret = 0;
    long long start = 5;

    while (true)
    {
        ret += val / start;        
        start *= 5;
        if (start > val) break;
    }

    return ret;
}

int GetZeroCountWithTwo(int val)
{
    int ret = 0;
    long long start = 2;

    while (true)
    {
        ret += val / start;
        start *= 2;
        if (start > val) break;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, K = 0;

    cin >> N >> K;     

    cout << min((GetZeroCountWithFive(N) - GetZeroCountWithFive(N - K)) - GetZeroCountWithFive(K),
        (GetZeroCountWithTwo(N) - GetZeroCountWithTwo(N - K)) - GetZeroCountWithTwo(K));
}