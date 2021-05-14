#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> px, py;
    for (int i = 0; i < 3; ++i)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        px.push_back(x);
        py.push_back(y);
    }

    sort(px.begin(), px.end());
    sort(py.begin(), py.end());

    int ax = 0, ay = 0;
    if (px[0] == px[1]) ax = px[2];
    else ax = px[0];
    if (py[0] == py[1]) ay = py[2];
    else ay = py[0];
    cout << ax << " " << ay;
}