#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int T = 0, I = 0, startX = 0, startY = 0, destX = 0, destY = 0;
int map[300][300];
int cnt[300][300];
int ix[8]{ -2, -1, 1, 2, 2, 1, -1, -2 }, iy[8]{ -1, -2, -2, -1, 1, 2, 2, 1 };
bool IsAvaliableIndex(int x, int y)
{
    return (x >= 0 && x < I) && (y >= 0 && y < I);
}
void BFS()
{
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	map[startY][startX] = 1;
	cnt[startY][startX] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nx = x + ix[i];
			int ny = y + iy[i];

			if (IsAvaliableIndex(nx, ny) && map[ny][nx] == 0)
			{
				map[ny][nx] = 1;
				cnt[ny][nx] = cnt[y][x] + 1;
				q.push({ nx, ny });
			}
		}		
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> I;
        cin >> startX >> startY;
        cin >> destX >> destY;
		memset(map, 0, sizeof(map));
		memset(cnt, 0, sizeof(cnt));
		BFS();
		cout << cnt[destY][destX] - 1 << "\n";
    }	
}