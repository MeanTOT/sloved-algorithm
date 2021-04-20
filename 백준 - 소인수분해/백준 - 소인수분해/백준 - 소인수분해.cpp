#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N = 0;
vector<int> result;
void solution()
{
	int sqrtN = (int)sqrt(N);
	for (int i = 2; i <= sqrtN; ++i)
	{
		while (N % i == 0)
		{
			N /= i;
			result.push_back(i);
		}		
	}
	if (N > 1) result.push_back(N);
}
int main()
{
	cin >> N;
	solution();
	for (size_t i = 0; i < result.size(); i++) printf("%d\n", result[i]);
}