#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector<int> amounts;
int N = 0;
int cache[10001][3];
int dp(int index, int stack)
{
	if (index >= N) return 0;
	if (index == N - 1 && stack != 2) return amounts[N - 1];

	int& result = cache[index][stack];
	if (result != -1) return result;

	if (stack != 2)
		result = amounts[index] + max(result, dp(index + 1, stack + 1));
	result = max(result, dp(index + 1, 0));

	return result;
}
int solution()
{
	return dp(0, 0);
}
int main()
{
	cin >> N;
	amounts.resize(N);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)
	{
		cin >> amounts[i];
	}

	cout << solution();
}