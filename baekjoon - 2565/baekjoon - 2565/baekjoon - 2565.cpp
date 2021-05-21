#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int N = 0;
vector<pair<int, int>> lines;
int cache[101];

int Dp(int start)
{
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;

	for (int i = start + 1; i < N; ++i)
	{
		if (lines[start].second < lines[i].second)
			ret = max(ret, Dp(i) + 1);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		lines.push_back(make_pair(a, b));
	}

	memset(cache, -1, sizeof(cache));
	sort(lines.begin(), lines.end());

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		result = max(result, Dp(i));
	}

	cout << N - result;
}