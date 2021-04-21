#include <iostream>
using namespace std;
int GetX(int ni, int ret, int mod)
{
	int x = 1;
	while (true)
	{
		if ((x * ni) % mod == ret)
			return x;
		++x;
	}
}
int main()
{
	int E_MAX = 15;
	int S_MAX = 28;
	int M_MAX = 19;
	int E, S, M = 0;
	cin >> E >> S >> M;
	if (E == E_MAX && S == S_MAX && M == M_MAX) cout << 7980;
	else
	{
		int u1 = GetX(((S_MAX * M_MAX) % E_MAX), E % E_MAX, E_MAX);
		int u2 = GetX(((E_MAX * M_MAX) % S_MAX), S % S_MAX, S_MAX);
		int u3 = GetX(((S_MAX * E_MAX) % M_MAX), M % M_MAX, M_MAX);
		cout << ((u1 * S_MAX * M_MAX) + (u2 * E_MAX * M_MAX) + (u3 * S_MAX * E_MAX)) % (E_MAX * S_MAX * M_MAX);
	}	
}