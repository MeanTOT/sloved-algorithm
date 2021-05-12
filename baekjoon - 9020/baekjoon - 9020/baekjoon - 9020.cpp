#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;
int T = 0, N = 0;

bool isPrime[10001];
void eratosthenes()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(10000));
	for (int i = 2; i <= sqrtn; ++i)
		if (isPrime[i])
			for (int j = i * i; j <= 10000; j += i)
				isPrime[j] = false;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
	eratosthenes();
    while (T--)
    {
        cin >> N;

		int a = N / 2, b = N / 2;
		while (isPrime[a] == false)	--a;
		while (isPrime[b] == false) ++b;

		while (true)
		{
			if (a + b > N)
			{
				--a;
				while (isPrime[a] == false)
				{
					--a;
				};
			}
			else if (a + b < N)
			{
				++b;
				while (isPrime[b] == false)
				{
					++b;
				};
			}
			else if (a + b == N)
			{
				break;
			}
		}

		cout << a << " " << b << "\n";
    }		
}