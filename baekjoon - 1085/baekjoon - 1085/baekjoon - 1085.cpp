#include <iostream>
using namespace std;
int main()
{
    int x = 0, y = 0, w = 0, h = 0;
    cin >> x >> y >> w >> h;

    int c1 = min(x, w - x);
    int c2 = min(y, h - y);
    cout << min(c1, c2);
}