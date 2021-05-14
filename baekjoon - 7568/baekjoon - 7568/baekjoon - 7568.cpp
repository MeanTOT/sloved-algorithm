#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Info
{
	int no;
	int weight = 0;
	int height = 0;
	int rank;
};
int N = 0, x = 0, y = 0;
vector<Info> database;

bool CompWeight(Info a, Info b)
{
	if (a.weight == b.weight)
		return a.height > b.height;

	return a.weight > b.weight;
}
bool CompNo(Info a, Info b)
{
	return a.no < b.no;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		database.push_back({ i, x, y, 0 });
	}
	sort(database.begin(), database.end(), CompWeight);
	for (int i = 0; i < database.size(); ++i)
	{
		int upperCount = 1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (database[i].weight < database[j].weight && database[i].height < database[j].height)
				upperCount++;
		}
		database[i].rank = upperCount;
	}
	sort(database.begin(), database.end(), CompNo);
	for (int i = 0; i < database.size(); ++i)
	{
		cout << database[i].rank << " ";
	}
}