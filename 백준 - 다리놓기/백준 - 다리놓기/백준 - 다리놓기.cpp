#include <iostream>
#include <memory.h>
using namespace std;
int M = 0;
int N = 0;
int cache[31][31];
int dp(int m, int n)
{
	if (m == n || n == 0)
		return 1;
	if (cache[m][n])return cache[m][n];
	return cache[m][n] = dp(m - 1, n - 1) + dp(m - 1, n);
}
int main()
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		memset(cache, 0, sizeof(cache));
		cin >> N >> M;
		cout << dp(M, N) << endl;
	}
}
