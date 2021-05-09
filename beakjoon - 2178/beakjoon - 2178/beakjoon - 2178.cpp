#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;
int N = 0, M = 0; vector<vector<char>> map;
int cnt[100][100];
int Answer = 0;
int xP[4] = { 1,0,-1,0 };
int yP[4] = { 0,1,0,-1 };
bool isAvaliableIndex(int x, int y) 
{
	return(y >= 0 && y < N) && (x >= 0 && x < M);
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	pair<int, int> pos;
	q.push(make_pair(x, y));
	map[y][x] = 0;
	int _x = 0, _y = 0;
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			_x = pos.first + xP[i];
			_y = pos.second + yP[i];

			if (isAvaliableIndex(_x, _y) && map[_y][_x] == 1)
			{
				q.push(make_pair(_x, _y));
				map[_y][_x] = 0;
				cnt[_y][_x] = cnt[pos.second][pos.first] + 1;
			}
		}
	}
}

int main()
{
	int a = scanf("%d %d", &N, &M);
	map.resize(N);
	memset(cnt, 0, sizeof(cnt));
	cnt[0][0] = 1;
	for (int i = 0; i < N; ++i)
	{
		map[i].resize(M);
		for (int j = 0; j < M; ++j)
		{
			int room = 0;
			int a = scanf("%1d", &room);
			map[i][j] = room;
		}
	}
	BFS(0, 0);	
	cout << cnt[N - 1][M - 1];
}