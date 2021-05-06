#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector<int> adj[102];
bool visited[102];
int computers = 0, edge = 0, answer = 0;
void DFS(int here)
{
	answer++;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (!visited[there])
			DFS(there);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> computers;
	cin >> edge;
	for (int i = 0; i < edge; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	DFS(1);
	cout << answer - 1;
}