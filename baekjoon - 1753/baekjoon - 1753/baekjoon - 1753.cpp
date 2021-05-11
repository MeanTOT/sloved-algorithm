#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
int V = 0, E = 0, K = 0, u = 0, v = 0, w = 0;
vector<vector<pair<int, int>>> adj;
vector<int> dijkstra(int start)
{
	vector<int> dist(V, INT_MAX);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}
int main()
{
    cin >> V >> E;
    cin >> K;
	adj.resize(V);
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;
		adj[u - 1].push_back({ w, v - 1 });
    }
	vector<int> result = dijkstra(K - 1);
	for (int i = 0; i < result.size(); ++i)
	{
		if (i == K - 1) cout << 0 << "\n";
		else if (i != K - 1 && result[i] == INT_MAX) cout << "INF" << "\n";
		else cout << result[i] << "\n";
	}
}