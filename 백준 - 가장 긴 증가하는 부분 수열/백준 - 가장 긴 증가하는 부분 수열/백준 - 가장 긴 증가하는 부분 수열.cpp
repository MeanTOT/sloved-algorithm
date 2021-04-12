#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int A = 0;
int cache[1001];
vector<int> numbers;
int dp(int start)
{
	int& result = cache[start];
	if (result != -1) return result;

	result = 1;
	for (size_t i = start + 1; i < numbers.size(); i++)
	{
		if (numbers[start] < numbers[i])
			result = max(result, dp(i) + 1);
	}
	return result;
}
int solution()
{
	int result = 0;
	for (size_t i = 0; i < numbers.size(); i++)
		result = max(result, dp(i));
	return result;
}
int main()
{
	cin >> A;
	numbers.resize(A);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < A; i++)
	{
		cin >> numbers[i];
	}
	cout << solution();
}
