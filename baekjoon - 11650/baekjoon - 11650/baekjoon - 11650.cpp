#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> coordinates;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}
int main()
{
    int N = 0;
    cin >> N;
    while (N--)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }

    sort(coordinates.begin(), coordinates.end(), comp);

    for (int i = 0; i < coordinates.size(); ++i)
    {
        cout << coordinates[i].first << " " << coordinates[i].second << "\n";
    }

}