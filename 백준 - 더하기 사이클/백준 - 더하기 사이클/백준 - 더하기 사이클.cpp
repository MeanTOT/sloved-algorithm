#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N, newN= 0;
	int result = 0;
	cin >> N;
	newN = N;
	while (true)
	{
		if (newN < 10) newN = newN * 11;
		else newN = ((newN % 10) * 10) + (((newN / 10) + (newN % 10)) % 10);
		result++;
		if (newN == N) break;
	}
	printf("%d", result);
}