#include <iostream>
#include <vector>
using namespace std;
vector<int> set;
int Find(int u)
{
    if (u == set[u]) return u;
    return set[u] = Find(set[u]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    set[u] = v;
}

int main()
{
    int N = 0, M = 0;
    cin >> N;
    cin >> M;
    set.resize(N + 1);
    for (int i = 1; i < N + 1; ++i) set[i] = i;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int city = 0;
            cin >> city;
            if (city == 1)
            {
                Union(i, j);
            }
        }
    }
    int parent = -1;
    bool isPossblePlan = true;
    for (int i = 0; i < M; ++i)
    {
        int path = 0;
        cin >> path;

        if (parent == -1) parent = Find(path);
        else if (parent != Find(path)) isPossblePlan = false;
    }    
    if (isPossblePlan) cout << "YES";
    else cout << "NO";
}