#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool Comp(vector<int> v1, vector<int> v2) { return v1[0] < v2[0]; }

bool isInRange(vector<int> dests, int start)
{
	for (int i = 0; i < dests.size(); i++)
		if (start > dests[i])
			return false;

	return true;
}

int solution(vector<vector<int>> routes)
{
	int answer = 1;
	sort(routes.begin(), routes.end(), Comp);
	vector<int> dests;

	for (int i = 0; i < routes.size(); i++)
	{
		if (!isInRange(dests, routes[i][0]))
		{
			answer++;
			dests.clear();
		}

		dests.push_back(routes[i][1]);
	}

	return answer;
}

int main()
{
	vector<vector<int>> routes = { {0, 1} ,{2,3},{4,5},{6,7} };
	//[[-20,15], [-14,-5], [-18,-13], [-5,-3]]	
	solution(routes);

	return 0;
}