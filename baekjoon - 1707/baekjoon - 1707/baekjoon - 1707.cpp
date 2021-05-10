#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int K = 0, V = 0, E = 0;
const int NONE = 0, RED = 1, BLUE = 2;
vector<vector<int>> adj;
vector<int> visited;
bool ansFlag = false;
int ChangeColor(int currentColor)
{
	if (currentColor == RED) return BLUE;
	if (currentColor == BLUE) return RED;
}
void DFS(int here)
{
	if (ansFlag) return;
	if (visited[here] == NONE)
		visited[here] = RED;
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (visited[there] == NONE)
		{
			if (visited[here] == RED)
				visited[there] = BLUE;
			else if (visited[here] == BLUE)
				visited[there] = RED;
	
			DFS(there);
		}
		if (visited[there] == visited[here]) ansFlag = true;
	}	
}

void DFSAll()
{	
	int result = true;
	for (int i = 1; i <= V; ++i)
	{
		if (visited[i] == NONE)
		{
			DFS(i);
			if (ansFlag)
			{
				result = false;
				break;
			}				
		}		
	}

	if (result) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> K;
    while (K--)
    {
        cin >> V >> E;
		ansFlag = false;
		adj.clear();
        adj.resize(V + 1);
		visited.clear();
		visited.resize(V + 1);
		for (int i = 1; i <= V; ++i) adj[i].clear();
        for (int i = 0; i < E; ++i)
        {
            int node1 = 0, node2 = 0;
            cin >> node1 >> node2;            
			adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
		DFSAll();		
    }	
}