#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int M = 0, N = 0, H = 0, _x = 0, _y = 0, _z = 0, Result = 0;
vector<vector<vector<int>>> box;
vector<tuple<int, int, int>> StartTomatoPos;
queue<tuple<int, int, int>> q;
int cnt[100][100][100];
int xP[6] = { 1, 0, -1, 0, 0, 0 }, yP[6] = { 0, 1, 0, -1, 0, 0 }, zP[6] = { 0, 0, 0, 0, 1, -1 };
bool IsAvaliableIndex(int x, int y, int z)
{
	return ((y >= 0 && y < N) && (x >= 0 && x < M) && (z >= 0 && z < H)) && box[z][y][x] != -1;
}
void BFS()
{
	for (int i = 0; i < StartTomatoPos.size(); ++i) q.push(StartTomatoPos[i]);
	while (!q.empty())
	{
		tuple<int, int, int> here = q.front(); q.pop();
		for (int i = 0; i < 6; ++i)
		{
			_x = get<0>(here) + xP[i];
			_y = get<1>(here) + yP[i];
			_z = get<2>(here) + zP[i];

			if (IsAvaliableIndex(_x, _y, _z) && box[_z][_y][_x] == 0)
			{
				q.push(make_tuple(_x, _y, _z));
				box[_z][_y][_x] = 1;
				cnt[_z][_y][_x] = cnt[get<2>(here)][get<1>(here)][get<0>(here)] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> M >> N >> H;
	box.resize(H);
	for (int k = 0; k < H; ++k)
	{
		box[k].resize(N);
		for (int i = 0; i < N; ++i)
		{			
			box[k][i].resize(M);
			for (int j = 0; j < M; ++j)
			{
				int tomato = 0;
				cin >> tomato;
				box[k][i][j] = tomato;
				if (tomato == 1)
				{
					StartTomatoPos.push_back(make_tuple(j, i, k));
					cnt[k][i][j] = 1;
				}
				else if (tomato == -1)
				{
					cnt[k][i][j] = -1;
				}
			}
		}
	}
	BFS();
	bool isAvaliableAnswer = true;
	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (cnt[k][i][j] == 0)
				{
					Result = 0;
					isAvaliableAnswer = false;
					break;
				}

				Result = max(Result, cnt[k][i][j]);
			}
			if (!isAvaliableAnswer) break;
		}
		if (!isAvaliableAnswer) break;
	}
	cout << Result - 1;
}