#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int N = 0, M = 0, newX = 0, newY = 0;
int map[1002][1002];
int cnt[1002][1002][2];
int ix[4] = { 1, 0, -1, 0 }, iy[4] = { 0, 1, 0 ,-1 };
bool IsAvaliableIndex(int x, int y)
{
	return ((x >= 1 && x <= M) && (y >= 1 && y <= N));
}
int BFS()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 1));
	cnt[1][1][1] = 1;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (y == N && x == M)
			return cnt[y][x][block];

		for (int i = 0; i < 4; ++i)
		{
			newX = x + ix[i];
			newY = y + iy[i];

			if (IsAvaliableIndex(newX, newY))
			{
				if (map[newY][newX] == 1 && block)
				{
					cnt[newY][newX][block - 1] = cnt[y][x][block] + 1;
					q.push({ {newX, newY}, block - 1 });
				}
				else if (map[newY][newX] == 0 && cnt[newY][newX][block] == 0)
				{
					cnt[newY][newX][block] = cnt[y][x][block] + 1;
					q.push({ {newX, newY}, block });
				}
			}
		}
	}

	return -1;
}
int main()
{
	int a = scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int node = 0;
			int a = scanf("%1d", &node);
			map[i][j] = node;
		}
	}
	cout << BFS();
}