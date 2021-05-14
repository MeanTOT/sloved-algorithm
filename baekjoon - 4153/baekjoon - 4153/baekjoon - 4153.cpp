#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{    
    while (true)
    {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;

        if ((a[0] * a[0]) + (a[1] * a[1]) == (a[2] * a[2]))
            cout << "right" << "\n";
        else
            cout << "wrong" << "\n";
    }
}