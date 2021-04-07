#include <iostream>
#include <memory.h>
using namespace std;
int cache[1001];
int solution(int N)
{
	if (N < 0) return 0;
	if (N == 0) return 1;

	int& result = cache[N];
	if (result != 0)
		return result;

	result += solution(N - 1);
	result += solution(N - 2);

	return result % 10007;
}
int main()
{
	int N = 0;
	cin >> N;
	memset(cache, 0, sizeof(cache));
	cout << solution(N);
}