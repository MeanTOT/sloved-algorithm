#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N = 0;
vector<pair<int, int>> times;
int Comp(pair<int, int> time1, pair<int, int> time2)
{
    if (time1.second == time2.second)
        return time1.first < time2.first;

    return time1.second < time2.second;
}
int Solution()
{
    sort(times.begin(), times.end(), Comp);
    int result = 0;
    int endTime = 0;
    for (int i = 0; i < N; i++)
    {
        if (times[i].first >= endTime)
        {
            endTime = times[i].second;
            result++;
        }
    }
    return result;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int start = 0;
        int end = 0;
        cin >> start >> end;
        times.push_back(make_pair(start, end));
    }
    cout << Solution();
}