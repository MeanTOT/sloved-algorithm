#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, ret = 0;
    cin >> N;    
    for (int i = 2; i <= N; ++i)
    {
        if (i % 5 == 0) ret++;
        if (i % 25 == 0) ret++;
        if (i % 125 == 0) ret++;
    }
    cout << ret;
}