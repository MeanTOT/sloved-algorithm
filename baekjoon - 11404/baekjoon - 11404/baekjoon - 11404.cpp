#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int V = 0, M = 0, a = 0, b = 0, c = 0;
vector<vector<pair<int, int>>> adj;
vector<int> dijkstra(int start)
{
	vector<int> dist(V + 1, INT_MAX);
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
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> V;
	cin >> M;
	adj.resize(V + 1);
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}

	for (int i = 1; i <= V; ++i)
	{
		vector<int> result = dijkstra(i);

		for (int i = 1; i < result.size(); ++i)
		{
			if (result[i] == INT_MAX) cout << 0 << " ";
			else cout << result[i] << " ";
		}
		cout << "\n";
	}
}