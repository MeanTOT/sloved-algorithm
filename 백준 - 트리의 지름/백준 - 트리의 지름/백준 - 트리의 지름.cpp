#include <iostream>
#include <vector>	
#include <map>
#include <algorithm>
using namespace std;
map<int, vector<pair<int, int>>> Tree;
int longest = 0;
int DFS(int parent, int current, int length)
{
	vector<pair<int, int>> node = Tree[current];
	if (node.size() == 1 && node[0].first == parent) return node[0].second;

	int result = 0;	
	vector<int> cadidates;
	for (int i = 0; i < node.size(); ++i) if (node[i].first != parent) cadidates.push_back(DFS(current, node[i].first, node[i].second));
	sort(cadidates.begin(), cadidates.end(), less<int>());
	if (cadidates.size() >= 2) result = cadidates[cadidates.size() - 1] + cadidates[cadidates.size() - 2];
	else result = cadidates[0];
	longest = max(longest, result);
	return length + cadidates[cadidates.size() - 1];
}
int main()
{
	ios::sync_with_stdio(false);
	int V = 0;
	cin >> V;
	for (int i = 0; i < V; ++i)
	{
		int N, A, B = 0;
		cin >> N;
		while (true)
		{
			cin >> A;
			if (A == -1) break;
			cin >> B;
			Tree[N].push_back(make_pair(A, B));
		}
	}
	vector<int> cadidates;
	vector<pair<int, int>> node = Tree[1];
	for (int i = 0; i < node.size(); i++) cadidates.push_back(DFS(1, node[i].first, node[i].second));
	sort(cadidates.begin(), cadidates.end(), less<int>());
	if (cadidates.size() >= 2) printf("%d", max(cadidates[cadidates.size() - 1] + cadidates[cadidates.size() - 2], longest));
	else printf("%d", max(cadidates[0], longest));
}