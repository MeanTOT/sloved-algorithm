#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector<vector<int>> numbers;
int cache[501][502];
int dp(int height, int index)
{
	if (height == numbers.size()) return 0;

	int& result = cache[height][index];
	if (result != -1) return result;

	return result = numbers[height][index] + max(dp(height + 1, index), dp(height + 1, index + 1));;
}
int main()
{
	int N = 0;
	cin >> N;
	numbers.resize(N);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)
	{
		numbers[i].resize(i + 1);
		for (int j = 0; j < i + 1; j++)
		{
			cin >> numbers[i][j];
		}
	}
	cout << dp(0, 0);
}