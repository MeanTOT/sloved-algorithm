#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int const MAX = 2147483647;
int cache[1001][3];
int dp(vector<vector<int>>& costs, int index, int previousColor)
{
	if (index == costs.size())
		return 0;

	int choiced = MAX;
	for (int i = 0; i < 3; i++)
	{
		if (i != previousColor)
		{
			int& result = cache[index][i];
			if (result != -1)
			{
				choiced = min(choiced, result);
				continue;
			}
				

			result = MAX;
			result = min(costs[index][i] + dp(costs, index + 1, i), result);

			if (choiced >= result)
				choiced = result;
		}
	}

	return choiced;
}
int solution(vector<vector<int>>& costs)
{
	return dp(costs, 0, -1);
}
int main()
{
	int N = 0;
	cin >> N;
	vector<vector<int>> costs;
	costs.resize(N);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)
	{
		costs[i].resize(3);
		cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
	}
	cout << solution(costs);
}