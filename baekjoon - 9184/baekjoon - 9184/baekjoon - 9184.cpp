#include <iostream>
#include <memory.h>
using namespace std;
int cache[101][101][101];
int w(int a, int b, int c)
{
    int& ref = cache[a + 50][b + 50][c + 50];
    if (ref != -1) return ref;

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return ref = w(20, 20, 20);
    if (a < b && b < c)
        return ref = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    
    return ref = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);        
    memset(cache, -1, sizeof(cache));
    while (true)
    {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}