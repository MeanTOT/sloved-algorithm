#include <iostream>
#include <memory.h>
using namespace std;
int N = 0;
int fibo[1000001];
const int MOB = 15746;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	memset(fibo, 0, sizeof(fibo));
	fibo[1] = 1;
	fibo[2] = 2;
	fibo[3] = 3;
	if (N < 4) cout << fibo[N] % MOB;
	else
	{
		for (int i = 4; i <= N; ++i)
		{
			fibo[i] = ((fibo[i - 1] % MOB) + (fibo[i - 2] % MOB)) % MOB;
		}
		cout << fibo[N] % MOB;
	}	
}