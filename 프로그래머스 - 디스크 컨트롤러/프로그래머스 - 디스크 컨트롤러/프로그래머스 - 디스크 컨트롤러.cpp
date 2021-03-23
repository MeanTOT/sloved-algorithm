#include <string>
#include <vector>
#include <queue>    
#include <algorithm>
#include <iostream>

using namespace std;

struct Compare
{
	bool operator()(vector<int> v1, vector<int> v2)
	{
		if (v1[1] == v2[1])
		{
			return v1[0] > v2[0];
		}

		return v1[1] > v2[1];
	}
};

bool comp(vector<int> v1, vector<int> v2)
{
	if (v1[0] == v2[0])
	{
		return v1[1] < v2[1];
	}

	return v1[0] < v2[0];
}

int solution(vector<vector<int>> jobs) 
{
	priority_queue<vector<int>, vector<vector<int>>, Compare> jobsQ;
	sort(jobs.begin(), jobs.end(), comp);

	int answer = 0;
	int currentTime = 0;
	int index = 0;
	while (index < jobs.size() || !jobsQ.empty())
	{
		while (index < jobs.size() && jobs[index][0] <= currentTime)
		{
			jobsQ.push(jobs[index++]);
		}

		if (jobsQ.empty())
			currentTime = jobs[index][0];
		else
		{
			vector<int> job = jobsQ.top();
			jobsQ.pop();
			answer += currentTime - job[0] + job[1];
			currentTime += job[1];
		}
	}

	return answer / jobs.size();
}

int main()
{
	vector<vector<int>> jobs = { {24, 10},{28, 39},{43, 20},{37, 5},{47, 22},{20, 47},{15, 34},{15, 2},{35, 43},{26, 1} };
	//vector<vector<int>> jobs = { {0, 10},{2, 10}, { 9, 10 }, { 15, 2 } };
	//vector<vector<int>> jobs = { {0, 3} ,{1, 9 }, { 2, 6 } };
	cout << solution(jobs);

	return 0;
}