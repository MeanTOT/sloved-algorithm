#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int, vector<pair<int, int>>> Tree;
int LongestPath = 0;
int Search(int current)
{
	vector<pair<int, int>> lines = Tree[current];	
	int n = lines.size();
	if (n == 0) return 0;

	int finalResult = 0;
	vector<int> results;
	for (int i = 0; i < n; ++i)
		results.push_back(lines[i].second + Search(lines[i].first));

	sort(results.begin(), results.end());
	if (results.size() >= 2)
		finalResult = results[results.size() - 2] + results[results.size() - 1];		
	else
		finalResult = results[0];		

	LongestPath = max(LongestPath, finalResult);
	return results[results.size() - 1];
}
int main()
{
	ios::sync_with_stdio(false);
	int N = 0;
	cin >> N;
	for (int i = 0 ; i < N - 1; ++i)
	{
		int parent = 0, child = 0, cost = 0;
		cin >> parent >> child >> cost;
		Tree[parent].push_back(make_pair(child, cost));
	}
	Search(1);
	cout << LongestPath;
}