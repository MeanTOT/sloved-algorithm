#include <iostream>
#include <string>   
#include <memory.h>

using namespace std;

int cache[1000001];

int solution(int N)
{
	memset(cache, 0, sizeof(cache));	
	cache[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		cache[i] = cache[i - 1] + 1;
		if (i % 2 == 0) cache[i] = min(cache[i], cache[i / 2] + 1);
		if (i % 3 == 0) cache[i] = min(cache[i], cache[i / 3] + 1);
	}
	return cache[N];
}

int main()
{
	int N = 0;
	cin >> N;
	cout << solution(N);
}