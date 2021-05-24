#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N = 0, K = 0, W = 0, V = 0;
vector<pair<int, int>> Objects;
int cache[101][100001];
int DP(int start, int weight)
{
    int& ret = cache[start][weight];
    if (ret != -1) return ret;
    ret = Objects[start].second;

    for (size_t i = start + 1; i < Objects.size(); ++i)
    {
        if (weight + Objects[i].first <= K)
        {
            ret = max(ret, DP(i, weight + Objects[i].first) + Objects[start].second);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; ++i)
    {
        cin >> W >> V;
        Objects.push_back(make_pair(W, V));
    }

    int ret = 0;
    for (size_t i = 0; i < Objects.size(); ++i)
    {
        if (Objects[i].first <= K)
            ret = max(ret, DP(i, Objects[i].first));
    }
    cout << ret;
}