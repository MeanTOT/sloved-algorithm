#include <iostream>
using namespace std;
int main()
{
    int X = 0, n = 1, sum = 0;;
    cin >> X;   
    while (true)
    {
        sum = ((n + 1) * n) / 2;
        if (sum >= X) break;
        ++n;
    }
    if (n % 2 == 0) cout << n - (sum - X) << "/" << 1 + (sum - X);
    else cout << 1 + sum - X << "/" << n - (sum - X);
}