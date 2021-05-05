#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
int n = 0, m = 0, caseNumber = 0;
void DFS(int here, bool& isTree, int prev)
{
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (there == prev) continue;
		if (visited[there])
		{
			isTree = false;
			return;
		}
		else
		{
			DFS(there, isTree, here);
			if (!isTree) return;
		};
	}
	isTree = true;
}

int DFSAll()
{
	int result = 0;
	bool isTree = true;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			DFS(i, isTree, 0);
			if (isTree) result++;
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);	
	while (true)
	{
		cin >> n >> m;
		if (m == 0 && n == 0) break;
		adj = vector<vector<int>>(n, vector<int>());
		visited = vector<bool>(n, false);
		for (int i = 0; i < m; ++i)
		{
			int v1 = 0, v2 = 0;
			cin >> v1 >> v2;
			adj[v1 - 1].push_back(v2 - 1);
			adj[v2 - 1].push_back(v1 - 1);
		}
		int result = DFSAll();
		cout << "Case " << ++caseNumber;
		if (result == 0) cout << ": No trees.";
		else if (result == 1) cout << ": There is one tree.";
		else cout << ": A forest of " << result << " trees.";
		cout << '\n';
	}
	return 0;
}