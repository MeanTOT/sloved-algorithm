#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
vector<tuple<int, int, int>> coord;
bool Comp(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<1>(a) < get<1>(b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x = 0;
        cin >> x;

        coord.push_back({ x, i + 1, 0 });
    }

    sort(coord.begin(), coord.end());

    int count = 0;
    for (int i = 1; i < N; ++i)
    {
        if (get<0>(coord[i]) != get<0>(coord[i - 1])) get<2>(coord[i]) = ++count;
        else get<2>(coord[i]) = count;
    }

    sort(coord.begin(), coord.end(), Comp);

    for (int i = 0; i < N; ++i)
    {
        cout << get<2>(coord[i]) << " ";
    }
}