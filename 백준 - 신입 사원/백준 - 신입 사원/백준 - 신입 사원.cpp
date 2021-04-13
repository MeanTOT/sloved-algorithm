#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T = 0;
int N = 0;
vector<pair<int, int>> specs;
vector<int> answers;
int solution()
{
	sort(specs.begin(), specs.end());
	int result = 0;
	int compSpec = 100001;
	for (int i = 0; i < N; i++)
	{
		if (compSpec > specs[i].second)
		{
			compSpec = specs[i].second;
			result++;
		}
	}
	return result;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int spec1 = 0;
			int spec2 = 0;
			cin >> spec1 >> spec2;
			specs.push_back(make_pair(spec1, spec2));
		}
		answers.push_back(solution());
		specs.clear();
	}

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << endl;
	}
}