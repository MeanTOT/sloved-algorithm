#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<string> words;
unordered_map<char, int> ciphers;
bool comp(pair<char, int> p1, pair<char, int> p2) { return p1.second > p2.second; }
int solution()
{
	int result = 0;
	for (int i = 0; i < words.size(); i++)
	{
		int cipher = 1;
		for (int j = words[i].length() - 1; j >= 0; j--)
		{
			ciphers[words[i][j]] += cipher;
			cipher *= 10;
		}
	}

	vector<pair<char, int>> ciphersVec(ciphers.begin(), ciphers.end());
	sort(ciphersVec.begin(), ciphersVec.end(), comp);

	int num = 9;
	for (int i = 0; i < ciphersVec.size(); i++)
	{
		result += ciphersVec[i].second * num;
		num--;
	}

	return result;
}
int main()
{
	int N = 0;
	cin >> N;
	words.resize(N);
	for (int i = 0; i < N; i++)
		cin >> words[i];
	cout << solution();
}