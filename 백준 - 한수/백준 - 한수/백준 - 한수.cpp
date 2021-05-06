#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool ap(int n)
{
    if (n < 100) return true;

    vector<int> aps;
    while (n >= 10)
    {
        aps.push_back(n % 10);
        n /= 10;
    }
    aps.push_back(n);
    bool result = true;
    int sub = aps[0] - aps[1];
    for (int i = 1; i < aps.size() - 1; i++)
    {
        if (aps[i] - aps[i + 1] != sub)
        {
            result = false;
            break;
        }
    }
    return result;
}

int main()
{
    int N = 0, result = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        if (ap(i)) result++;
    }
    cout << result;
}