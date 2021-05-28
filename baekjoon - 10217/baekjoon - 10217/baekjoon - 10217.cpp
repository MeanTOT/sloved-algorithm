#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int T = 0;
int N = 0, M = 0, K = 0, u = 0, v = 0, c = 0, d = 0;
const int INF = 987654321;
int dist[101][10001] = { 0 };

struct Ticket
{
	int dist = 0;
	int cost = 0;
	int dest = 0;
};

struct compare
{
	bool operator()(const Ticket& a, const Ticket& b) const
	{
		return a.dist < b.dist;
	}
};

void dijkstra(vector<vector<Ticket>>& adj)
{
	priority_queue<Ticket, vector<Ticket>, compare> distPQ;
	distPQ.push({ 0, 0, 1 });
	dist[1][0] = 0;
	while (!distPQ.empty())
	{
		Ticket cur = distPQ.top(); distPQ.pop();
		if (dist[cur.dest][cur.cost] < cur.dist) continue;

		int adjSize = adj[cur.dest].size();
		for (int i = 0; i < adjSize; ++i)
		{
			int there = adj[cur.dest][i].dest;
			int nextCost = cur.cost + adj[cur.dest][i].cost;
			int nextDist = cur.dist + adj[cur.dest][i].dist;

			if (nextCost > M) continue;
			if (dist[there][nextCost] > nextDist)
			{
				for (int j = nextCost + 1; j <= M; ++j)
				{
					if (dist[there][j] <= nextDist) break;						
					dist[there][j] = nextDist;
				}	

				dist[there][nextCost] = nextDist;
				distPQ.push({ nextDist, nextCost, there });
			}
		}
	}

	int Answer = INF;
	for (int i = 1; i <= M; ++i)
	{
		Answer = min(Answer, dist[N][i]);
	}
	if (Answer != INF)
		cout << Answer << "\n";
	else
		cout << "Poor KCM" << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;				

		vector<vector<Ticket>> adj;
		adj.resize(N + 1);
		for (int i = 0; i < K; ++i)
		{
			cin >> u >> v >> c >> d;
			adj[u].push_back({ d, c ,v });
		}		
		for (int i = 1; i <= N; ++i)
			for (int j = 0; j <= M; ++j)
				dist[i][j] = INF;
		dijkstra(adj);
	}
}