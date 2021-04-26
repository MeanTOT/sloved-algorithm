#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
string s = "baekjoon";
vector<int> group;
int t = 1;
bool Comp(int a, int b)
{	
	if (group[a] != group[b]) return group[a] < group[b];
	return group[a + t] < group[b + t];
}
vector<int> GetSuffixArray()
{
	int n = s.size();
	group.resize(n + 1);
	for (int i = 0; i < n; ++i) group[i] = s[i];
	group[n] = -1;
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;
	while (t < n)
	{
		sort(perm.begin(), perm.end(), Comp);
		t *= 2;
		if (t >= n) break;
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; ++i)
			if (Comp(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		group = newGroup;
	}
	return perm;
}
int main()
{
	GetSuffixArray();
}