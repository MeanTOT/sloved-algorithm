#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int M = 0, N = 0, _x = 0, _y = 0, Result = 0;
vector<vector<int>> box;
vector<pair<int, int>> StartTomatoPos;
queue<pair<int, int>> q;
int cnt[1000][1000];
int xP[4] = { 1, 0, -1, 0 }, yP[4] = { 0, 1, 0, -1 };
bool IsAvaliableIndex(int x, int y)
{
	return ((y >= 0 && y < N) && (x >= 0 && x < M)) && box[y][x] != -1;
}
void BFS()
{
	for (int i = 0; i < StartTomatoPos.size(); ++i) q.push(StartTomatoPos[i]);	
	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			_x = here.first + xP[i];
			_y = here.second + yP[i];

			if (IsAvaliableIndex(_x, _y) && box[_y][_x] == 0)
			{
				q.push(make_pair(_x, _y));
				box[_y][_x] = 1;
				cnt[_y][_x] = cnt[here.second][here.first] + 1;
			}
		}				
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> M >> N;
	box.resize(N);
	for (int i = 0; i < N; ++i)
	{
		box[i].resize(M);
		for (int j = 0; j < M; ++j)
		{
			int tomato = 0;
			cin >> tomato;
			box[i][j] = tomato;
			if (tomato == 1)
			{
				StartTomatoPos.push_back(make_pair(j, i));
				cnt[i][j] = 1;
			}
			else if (tomato == -1)
			{
				cnt[i][j] = -1;
			}
		}
	}
	BFS();	
	bool isAvaliableAnswer = true;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (cnt[i][j] == 0)
			{
				Result = 0;
				isAvaliableAnswer = false;
				break;
			}

			Result = max(Result, cnt[i][j]);
		}
		if (!isAvaliableAnswer) break;
	}
	cout << Result - 1;
}