#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, vector<int>> tree; vector<int> answer;
void SetAnswer(int parent, int current)
{
	int N = tree[current].size();
	for (int i = 0; i < N; ++i)
		if (tree[current][i] != parent)
		{
			SetAnswer(current, tree[current][i]);
			answer[tree[current][i]] = current;
		}
}
int main()
{	
	ios::sync_with_stdio(false);
	int N = 0; cin >> N; answer.resize(N + 1);
	for (int i = 0; i < N - 1; ++i)
	{
		int a, b = 0;
		cin >> a >> b;
		tree[a].push_back(b); tree[b].push_back(a);
	}
	for (int i = 0; i < tree[1].size(); ++i)
	{		
		answer[tree[1][i]] = 1;
		SetAnswer(1, tree[1][i]);
	}
	for (int i = 2; i < N + 1; ++i) printf("%d\n", answer[i]);
}