#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int V = 0, E = 0, a = 0, b = 0, c = 0;
vector<vector<pair<int, int>>> adj;

const int INF = 987654321;
vector<int> dijkstra(int start)
{
	vector<int> dist(V + 1, INF);
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
	cin >> V >> E;
	adj.resize(V + 1);
	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}

	vector<vector<int>> result(V + 1);
	for (int i = 1; i <= V; ++i)
		result[i] = dijkstra(i);
	
	int answer = INF;
	for (int i = 1; i <= V; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			if (i == j) continue;

			if (result[i][j] != INF && result[j][i] != INF)
				answer = min(answer, result[i][j] + result[j][i]);
		}
	}
	if (answer != INF)
		cout << answer;
	else
		cout << -1;
}
