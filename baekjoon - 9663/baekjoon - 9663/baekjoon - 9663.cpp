#include <iostream>
using namespace std;
int N = 0, Answer = 0;
int col[15];
bool IsPossiblePos(int level)
{
	for (int i = 0; i < level; ++i)
	{
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;
	}

	return true;
}

void PutQueen(int x)
{
	if (x == N) Answer++;
	else
	{
		for (int i = 0; i < N; ++i)
		{
			col[x] = i;
			if (IsPossiblePos(x))
			{
				PutQueen(x + 1);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	PutQueen(0);
	cout << Answer;
}