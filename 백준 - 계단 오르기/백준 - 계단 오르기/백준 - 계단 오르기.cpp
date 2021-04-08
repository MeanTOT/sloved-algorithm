#include <iostream>
#include <vector>
#include <cstdint>
#include <memory.h>
using namespace std;
vector<int> scores;
int N = 0;
int cache[301][2];
int dp(int index, int stack)
{
	if (index >= N) return -1000000;
	if (index == N - 1) return scores[N - 1];

	int& result = cache[index][stack];
	if (result != -1) return result;

	if (stack != 1)
		result = max(result ,scores[index] + dp(index + 1, stack + 1));
	result = max(result, scores[index] + dp(index + 2, 0));

	return result;
}
int solution(int N, vector<int>& scores)
{
	int result = -1;
	result = max(dp(0, 0), result);
	result = max(dp(1, 0), result);

	return result;
}
int main()
{
	cin >> N;
	scores.resize(N);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)
		cin >> scores[i];
	cout << solution(N, scores);
}