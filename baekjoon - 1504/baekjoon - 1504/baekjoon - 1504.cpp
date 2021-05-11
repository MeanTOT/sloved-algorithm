#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int V = 0, N = 0, v1 = 0, v2 = 0, w = 0, nv1 = 0, nv2 = 0;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> dist;
void dijkstra()
{	
	dist.resize(3);
	for (int j = 0; j < 3; j++)
	{		
		priority_queue<pair<int, int>> pq;
		dist[j].assign(V + 1, INT_MAX);
		if (j == 0)
		{
			dist[j][1] = 0;
			pq.push(make_pair(0, 1));
		}
		else if (j == 1)
		{
			dist[j][nv1] = 0;
			pq.push(make_pair(0, nv1));
		}
		else if (j == 2)
		{
			dist[j][nv2] = 0;
			pq.push(make_pair(0, nv2));
		}
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (dist[j][here] < cost) continue;
			for (int i = 0; i < adj[here].size(); ++i)
			{
				int there = adj[here][i].second;
				int nextDist = cost + adj[here][i].first;
				if (dist[j][there] > nextDist)
				{
					dist[j][there] = nextDist;
					pq.push(make_pair(-nextDist, there));
				}
			}
		}
	}		
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> V >> N;
	adj.resize(V + 1);
	for (int i = 0; i < N; ++i)
	{
		cin >> v1 >> v2 >> w;	
		adj[v1].push_back({ w,v2 });
		adj[v2].push_back({ w,v1 });
	}
	cin >> nv1 >> nv2;
	dijkstra();		
	int ans = min(dist[0][nv1] + dist[1][nv2] + dist[2][V], dist[0][nv2] + dist[1][V] + dist[2][nv1]);
	if (ans > 2100000000) cout << -1;
	else cout << ans;
}