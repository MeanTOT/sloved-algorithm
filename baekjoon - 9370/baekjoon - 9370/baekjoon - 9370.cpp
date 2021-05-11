#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
int T = 0, n = 0, m = 0, t = 0, s = 0, g = 0, h = 0, a = 0, b = 0, c = 0, x = 0;
vector<vector<pair<int, int>>> adj;
vector<int> cadidates;
vector<vector<int>> dist;
vector<int> starts;
int INTMAX = 210000001;
void dijkstra()
{	
	dist.clear();
	dist.resize(3);
	for (int j = 0; j < 3; ++j)
	{
		dist[j].clear();
		dist[j].assign(n + 1, INTMAX);
		dist[j][starts[j]] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, starts[j]));
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
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> t;
        cin >> s >> g >> h;		
		starts.clear();
		starts.push_back(s);
		starts.push_back(g);
		starts.push_back(h);
		adj.resize(n + 1);		
		for (int i = 1; i < n + 1; ++i)
		{
			adj[i].clear();
		}
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> c;
			adj[a].push_back({ c, b });
			adj[b].push_back({ c, a });
        }
		cadidates.clear();
        for (int i = 0; i < t; ++i)
        {
            cin >> x;
            cadidates.push_back(x);
        }

		dijkstra();
		sort(cadidates.begin(), cadidates.end());
		for (int i = 0; i < cadidates.size(); ++i)
		{
			int answer = min(dist[0][g] + dist[1][h] + dist[2][cadidates[i]], dist[0][h] + dist[1][cadidates[i]] + dist[2][g]);
			if (dist[0][cadidates[i]] < INTMAX && answer < INTMAX && dist[0][cadidates[i]] >= answer)
				cout << cadidates[i] << " ";
		}
		cout << "\n";
    }
}