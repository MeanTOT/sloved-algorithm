#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
void DFS(int here)
{	
	cout << here + 1 << " ";
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (!visited[there])
			DFS(there);
	}	
}

void BFS(int start)
{	
	visited = vector<bool>(adj.size(), false);
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		cout << here + 1 << " ";
		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i];
			if (!visited[there])
			{
				q.push(there);
				visited[there] = true;
			}
		}
	}
}

int main()
{
	int N = 0, M = 0, V = 0;
	cin >> N >> M >> V;
	adj.resize(N);
	visited.resize(N);
	for (int i = 0; i < M; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < N; ++i)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	DFS(V - 1);
	cout << endl;
	BFS(V - 1);
}