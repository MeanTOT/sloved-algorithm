#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int A = 0;
int MaxLength = 0;
int cache[1001];
vector<int> numbers;
int dp(int previous, int index, int length)
{
	if (index == numbers.size())
		return length;
	
	length++;
	int& result = cache[index];
	if (numbers[index] > previous)
	{		
		if (result != 0) return length + result;
		result = max(result,dp(numbers[index], index + 1, length));		
	}
	
	result = max(result, dp(previous, index + 1, length - 1));

	return result;
}
int solution()
{
	int result = 1;
	for (int i = numbers.size() - 1; i >= 0; i--)
	{
		result = max(result, dp(0, i, 0));
	}
	return result;
}
int main()
{
	cin >> A;
	numbers.resize(A);
	memset(cache, 0, sizeof(cache));
	for (int i = 0; i < A; i++)
	{
		cin >> numbers[i];
	}
	cout << solution();
}
