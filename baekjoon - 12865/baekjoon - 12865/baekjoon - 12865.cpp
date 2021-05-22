#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N = 0, K = 0, W = 0, V = 0;
vector<pair<int, int>> things;
int cache[101];
int dp(int index, int weight)
{
	int& ret = cache[index];
	//if (ret != -1) return ret;
	ret = things[index].second;

	for (int i = index + 1; i < N; ++i)
	{
		if (weight + things[i].first <= K)
		{
			ret = max(ret, things[index].second + dp(i, weight + things[i].first));
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> K;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; ++i)
	{
		cin >> W >> V;
		things.push_back(make_pair(W, V));
	}
	
	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		result = max(result, dp(i, things[i].first));
	}
	cout << result;
}