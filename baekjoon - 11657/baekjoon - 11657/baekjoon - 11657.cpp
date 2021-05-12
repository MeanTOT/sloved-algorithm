#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int V = 0, M = 0, A = 0, B = 0, C = 0;
vector<vector<pair<int, int>>> adj;
#define INF 987654321
void bellmanFord(int start)
{
	vector<long long> upper(V + 1, INF);
	upper[start] = 0;
	bool updated = false;
	for (int iter = 0; iter < V; ++iter)
	{
		updated = false;
		for (int here = 1; here <= V; ++here)
		{
			for (int i = 0; i < adj[here].size(); ++i)
			{
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (upper[here] != INF && upper[there] > upper[here] + cost)
				{
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}			
		}	
		if (!updated) break;
	}

	if (updated) cout << -1 << "\n";
	else
	{
		for (int i = 2; i <= V; ++i)
		{
			if (upper[i] == INF) cout << -1 << "\n";
			else cout << upper[i] << "\n";
		}
	}	
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> V >> M;
	adj.resize(V + 1);
	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B >> C;
		adj[A].push_back(make_pair(B, C));
	}

	bellmanFord(1);
}