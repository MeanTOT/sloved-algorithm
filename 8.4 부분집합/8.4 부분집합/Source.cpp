#include <iostream>
#include <vector>

using namespace std;

void GetSubSetAll(vector<int> set, vector<vector<vector<int>>>& subsetAll);
void GetSubSetOneline(vector<int> set, vector<vector<int>>& subsetOneline, int level);
void GetSubSet(vector<int> set, vector<vector<int>>& subsetOneline, int startIndex, int level);
void GetSubSet(vector<int> set, vector<vector<int>>& subsetOneline, vector<int>& stack, int startIndex, int level);
void GetSubSetRe(vector<int> set, vector<vector<int>>& subsetOneline, vector<int>& stack, int startIndex, int level);

int main()
{
	vector<int> set = { 1, 2, 3 };
	
	vector<vector<vector<int>>> subsetAll;	
	subsetAll.resize(set.size());

	GetSubSetAll(set, subsetAll);

	return 0;
}

void GetSubSetAll(vector<int> set, vector<vector<vector<int>>>& subsetAll)
{
	for (int i = 0; i < set.size(); i++)
	{
		GetSubSetOneline(set, subsetAll[i], i + 1);
	}
}

void GetSubSetOneline(vector<int> set, vector<vector<int>>& subsetOneline, int level)
{
	for (int i = 0; i < set.size(); i++)
	{
		GetSubSet(set, subsetOneline, i, level);
	}	
}

void GetSubSet(vector<int> set, vector<vector<int>>& subsetOneline, int startIndex, int level)
{
	vector<int> subset;
	GetSubSet(set, subsetOneline, subset, startIndex, level);
}

void GetSubSet(vector<int> set, vector<vector<int>>& subsetOneline, vector<int>& stack, int startIndex, int level)
{
	stack.push_back(set[startIndex]);
	level--;

	if (level == 0)
	{		
		subsetOneline.push_back(stack);
		return;
	}
	else
	{
		if (startIndex + level < set.size())
		{
			for (int i = startIndex + 1; i < set.size(); i++)
			{
				GetSubSetRe(set, subsetOneline, stack, i, level);
				stack.pop_back();
			}			
		}		
	}
}

void GetSubSetRe(vector<int> set, vector<vector<int>>& subsetOneline, vector<int>& stack, int startIndex, int level)
{
	stack.push_back(set[startIndex]);
	level--;

	if (level == 0)
	{
		subsetOneline.push_back(stack);
		return;
	}
	else
	{
		if (startIndex + level < set.size())
		{
			for (int i = 0; i < set.size() - startIndex + 1; i++)
			{
				GetSubSetRe(set, subsetOneline, stack, startIndex + 1, level);
			}
		}
	}
}

