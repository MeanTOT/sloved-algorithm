#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
long long solution(vector<int> a, vector<vector<int>> edges)
{
    long long answer = 0;

    int currPattern = 0;
    int sum = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        answer += abs(a[edges[i][currPattern]]);
        sum += a[edges[i][currPattern]];

        if (currPattern == 0) currPattern = 1;
        else if (currPattern == 1) currPattern = 0;
    }
    if (sum != 0) return -1;
    return answer;
}
int main()
{
    vector<int> a = {-5, 0, 2, 1, 2};
    vector<vector<int>> edges = { {0, 1},{3, 4},{2, 3},{0, 3} };

    std::cout << solution(a, edges);
}