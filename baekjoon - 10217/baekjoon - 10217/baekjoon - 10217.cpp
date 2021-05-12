#include <iostream>
#include <vector>	
#include <queue>
#include <limits.h>
using namespace std;
int T = 0, N = 0, M = 0, K = 0, u = 0, v = 0, c = 0, d = 0;
struct Node
{
	int dist = 0;	
	int cost = 0;
	int dest = 0;
};
void dijkstra(vector<vector<Node>>& adj)
{
	vector<int> dists(N + 1, INT_MAX);
	vector<int> costs(N + 1, 0);
	dists[1] = 0;
	priority_queue<Node> pq;
	pq.push({0, 0, 1});
	while (!pq.empty())
	{
		int dist = -pq.top().dist;		
		int cost = pq.top().cost;
		int here = pq.top().dest;
		pq.pop();

		if (dists[here] < dist || costs[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].dest;
			int nextCost = cost + adj[here][i].cost;
			int nextDist = dist + adj[here][i].dist;
			if (dists[there] > nextDist && nextCost < M)
			{
				dists[there] = nextDist;
				costs[there] = nextCost;
				pq.push({ nextDist, nextCost, there });
			}
		}
	}
	if (dists[N] >= 2100000000 || costs[N] > M) cout << "Poor KCM";
	else cout << dists[N];
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> K;
		vector<vector<Node>> adj;
		adj.resize(N + 1);
        for (int i = 0; i < K; ++i)
        {
            cin >> u >> v >> c >> d;
			adj[u].push_back({ d, c, v });
        }
		dijkstra(adj);
    }
}