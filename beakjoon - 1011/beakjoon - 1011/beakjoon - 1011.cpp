#include <iostream>
using namespace std;
int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        int x = 0, y = 0, dis = 1, result = 0;
        cin >> x >> y;
        while (true)
        {   
            x += dis;
            result++;
            if (x >= y) break;
            y -= dis;
            result++;
            if (y <= x) break;
            dis++;
        }
        cout << result << endl;
    }
}