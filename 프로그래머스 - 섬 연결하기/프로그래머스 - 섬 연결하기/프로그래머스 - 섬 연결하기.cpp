#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> roots;

bool Comp(vector<int> v1, vector<int > v2)
{
    return v1[2] < v2[2];
}

int Find(vector<int> roots, int x)
{
    if (roots[x] == x)
        return x;
    else
        return Find(roots, roots[x]);
}

void Union(vector<int>& roots, int x, int y)
{
    x = Find(roots, x);
    y = Find(roots, y);

    roots[y] = x;
}

// Kruskal 알고리즘과 Union-Find 알고리즘을 사용하였음.
int solution(int n, vector<vector<int>> costs) 
{
    for (int i = 0; i < n; i++)
        roots.push_back(i);

    sort(costs.begin(), costs.end(), Comp);    
    int answer = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if (Find(roots, costs[i][0]) == Find(roots, costs[i][1]))
            continue;

        Union(roots, costs[i][0], costs[i][1]);
        answer += costs[i][2];
    }
  
    return answer;
}

int main()
{
    vector<vector<int>> costs = { {{0, 1, 5},{0, 3, 2},{0, 4, 3},{1, 4, 1},{3, 4, 10},{1, 2, 2},{2, 5, 3},{4, 5, 4}} };
    cout << solution(6, costs);

    return 0;
};    