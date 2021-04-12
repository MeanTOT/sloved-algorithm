#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
vector<int> P;
int solution()
{
	int result = 0;
	int sum = 0;
	sort(P.begin(), P.end());
	for (int i = 0; i < N; i++)
	{
		sum += P[i];
		result += sum;
	}
	return result;
}
int main()
{
	cin >> N;
	P.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}
	cout << solution();
}