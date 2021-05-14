#include <iostream>
#include <vector>
using namespace std;
int N = 0, M = 0;
vector<vector<char>> ChessTable;
void ColorChange(char& color)
{
	if (color == 'W') color = 'B';
	else if (color == 'B') color = 'W';
}
int GetNeededCorrectCount(int _i, int _j)
{
	int result1 = 0, result2 = 0;
	char color1 = 'W';
	char color2 = 'B';
	for (int i = _i; i < _i + 8; ++i)
	{
		for (int j = _j; j < _j + 8; j += 2)
		{
			if (ChessTable[i][j] != color1) result1++;
			if (ChessTable[i][j + 1] != color2) result1++;

			if (ChessTable[i][j] != color2) result2++;
			if (ChessTable[i][j + 1] != color1) result2++;
		}
		char temp = color1;
		color1 = color2;
		color2 = temp;
	}
	return min(result1, result2);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	ChessTable.resize(N);
	for (int i = 0; i < N; ++i)
	{
		ChessTable[i].resize(M);
		for (int j = 0; j < M; ++j)
		{
			char color = ' ';
			cin >> color;
			ChessTable[i][j] = color;
		}
	}

	int result = 2501;
	for (int i = 0; i <= N - 8; ++i)
	{
		for (int j = 0; j <= M - 8; ++j)
		{
			result = min(result, GetNeededCorrectCount(i, j));
		}
	}
	cout << result;
}