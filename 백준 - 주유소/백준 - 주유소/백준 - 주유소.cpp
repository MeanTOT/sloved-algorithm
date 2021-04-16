#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<unsigned long long> dis;
vector<unsigned long long> price;
unsigned long long solution()
{
	unsigned long long result = 0;
	unsigned long long lastCasStation = price[0];
	unsigned long long distance = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (price[i] < lastCasStation)
		{
			result += lastCasStation * distance;
			lastCasStation = price[i];
			distance = 0;
		}
		distance += dis[i];
	}
	if (distance != 0) result += lastCasStation * distance;
	return result;
}
int main()
{
	cin >> N;
	dis.resize(N - 1);
	price.resize(N);
	for (int i = 0; i < N - 1; i++)
		cin >> dis[i];
	for (int i = 0; i < N; i++)
		cin >> price[i];
	printf("%llu", solution());
}