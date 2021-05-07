#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> depth;

int Find(int u) 
{
	if (u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return true;
    if (depth[u] > depth[v]) parent[v] = u;
    else if (depth[u] < depth[v]) parent[u] = v;
    else if (depth[u] == depth[v])
    {
        parent[u] = v;
        ++depth[v];
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    parent.resize(N);
    depth.resize(N);
    int result = 0;    
    for (int i = 0; i < N; ++i)
    {
        parent[i] = i;
        depth[i] = 1;
    }
    for (int i = 0; i < M; ++i)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        if (Union(a, b) && result == 0) result = i + 1;
    }

    cout << result;
}