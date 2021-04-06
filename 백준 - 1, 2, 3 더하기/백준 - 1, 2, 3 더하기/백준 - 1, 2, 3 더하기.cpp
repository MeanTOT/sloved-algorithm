#include <iostream>
#include <vector>
using namespace std;
int Answer = 0;

void solution(int current, int N)
{
	if (current > N)
		return;
	else if (current == N)
	{
		Answer++;
		return;
	}

	solution(current + 1, N);
	solution(current + 2, N);
	solution(current + 3, N);
}
int main()
{
	int T = 0;
	vector<int> Ns;
	cin >> T;
	Ns.resize(T);
	for (int i = 0; i < Ns.size(); i++)
	{
		cin >> Ns[i];
	}
	for (int i = 0; i < Ns.size(); i++)
	{
		Answer = 0;
		solution(0, Ns[i]);
		cout << Answer << endl;
	}
}