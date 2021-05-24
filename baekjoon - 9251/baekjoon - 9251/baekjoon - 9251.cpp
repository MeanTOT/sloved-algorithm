#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
string A = "", B = "";
int Answer = 0;
int cache[1001][1001];

int FindIndexAtB(int start, char target)
{
	for (int i = start; i < B.size(); ++i)
	{
		if (B[i] == target)
		{
			return i;
		}
	}

	return -1;
}

int Dp(int startA, int startB)
{
	int& ret = cache[startA][startB];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = startA; i < A.size(); ++i)
	{
		int IndexB = FindIndexAtB(startB, A[i]);
		if (IndexB != -1)
		{
			ret = max(ret, Dp(i + 1, IndexB + 1) + 1);
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> A;
	cin >> B;
	memset(cache, -1, sizeof(cache));

	int ret = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		ret = max(ret, Dp(i, 0));
	}
	cout << ret;
}