#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> farm;
int T = 0, M = 0, N = 0, K = 0;
void DFS(int here)
{
	visited[here] = true;
	for (size_t i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (!visited[there])
			DFS(there);
	}
}

int DFSAll()
{	
	int result = 0;
	for (int i = 0; i < adj.size(); ++i)
	{
		if (!visited[i] && farm[i / M][i % M])
		{
			result++;
			DFS(i);
		}
	}
	return result;
}
int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		adj.clear();
		adj.resize(M * N);
		visited.clear();
		visited.resize(M * N);
		farm.clear();
		farm.resize(N);
		for (int i = 0; i < N; ++i)
			farm[i].resize(M);
		for (int i = 0; i < K; ++i)
		{
			int X = 0, Y = 0;
			cin >> X >> Y;
			farm[Y][X] = 1;
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (i - 1 >= 0 && farm[i][j] && farm[i - 1][j]) adj[i * M + j].push_back((i - 1) * M + j);
				if (i + 1 < N && farm[i][j] && farm[i + 1][j]) adj[i * M + j].push_back((i + 1) * M + j);
				if (j - 1 >= 0 && farm[i][j] && farm[i][j - 1]) adj[i * M + j].push_back(i * M + j - 1);
				if (j + 1 < M && farm[i][j] && farm[i][j + 1]) adj[i * M + j].push_back(i * M + j + 1);				
			}
		}

		cout << DFSAll() << endl;
	}	
}