#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N = 0;
vector<int> arr;
int cacheLIS[1001];
int cacheLDS[1001];

int LDS(int start)
{
	int& ret = cacheLDS[start];
	if (ret != -1) return ret;
	ret = 1;

	for (int next = start + 1; next < N; ++next)
	{
		if (arr[start] > arr[next])
		{
			ret = max(ret, LDS(next) + 1);
		}
	}

	return ret;
}

int LIS(int start)
{
	int& ret = cacheLIS[start];
	if (ret != -1) return ret;
	ret = 1;

	for (int next = start + 1; next < N; ++next)
	{
		if (arr[start] < arr[next])
		{
			ret = max(ret, LIS(next) + 1);
		}
		else if (arr[start] > arr[next])
		{
			ret = max(ret, LDS(next) + 1);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	memset(cacheLIS, -1, sizeof(cacheLIS));
	memset(cacheLDS, -1, sizeof(cacheLDS));

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		result = max(result, LIS(i));
	}
	cout << result;
}