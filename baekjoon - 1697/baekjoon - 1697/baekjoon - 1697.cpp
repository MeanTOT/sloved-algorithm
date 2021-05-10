#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N = 0, K = 0;
int adj[300000];
int cnt[300000];
int VISITED = -100000;
bool IsAvaliableIndex(int index)
{
	return index >= 0 && index < 300000;
}
void BFS(int start)
{
	queue<int> q;
	q.push(start);
	adj[start] = VISITED;
	cnt[start] = 1;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		if (IsAvaliableIndex(here - 1) && adj[here - 1] != VISITED)
		{
			adj[here - 1] = VISITED;
			q.push(here - 1);
			cnt[here - 1] = cnt[here] + 1;

			if (here - 1 == K) break;
		}
		if (IsAvaliableIndex(here + 1) && adj[here + 1] != VISITED)
		{
			adj[here + 1] = VISITED;
			q.push(here + 1);
			cnt[here + 1] = cnt[here] + 1;

			if (here + 1 == K) break;
		}
		if (IsAvaliableIndex(here * 2) && adj[here * 2] != VISITED)
		{
			adj[here * 2] = VISITED;
			q.push(here  * 2);
			cnt[here * 2] = cnt[here] + 1;

			if (here * 2 == K) break;
		}
	}
}
int main()
{
    cin >> N >> K;
	BFS(N);
	cout << cnt[K] - 1;
}