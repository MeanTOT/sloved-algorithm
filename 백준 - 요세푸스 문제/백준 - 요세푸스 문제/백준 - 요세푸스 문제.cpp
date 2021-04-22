#include <iostream>
#include <vector>
using namespace std;
int N, K = 0;
vector<int> peaple;
vector<int> answer;
int main()
{
	int a = scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		peaple.push_back(i);
	
	int curr = -1;
	int count = 0;
	int remain = N;
	while (true)
	{		
		curr++;
		if (curr == N) curr = 0;
		if (peaple[curr] != -1)
			count++;
		if (count == K)
		{
			answer.push_back(peaple[curr]);
			peaple[curr] = -1;
			count = 0;
			remain--;

			if (remain == 0)break;
		}
	}

	printf("<");
	for (int i = 0; i < N; i++)
	{
		printf("%d", answer[i]);
		if (i != N - 1) printf(", ");
	}
	printf(">");
}