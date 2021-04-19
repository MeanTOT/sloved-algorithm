#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> tree;
vector<long long> A;
long long answer = 0;
void DFS(vector<vector<int>>& edges, int curr, int parent)
{
    for (size_t i = 0; i < tree[curr].size(); i++)
    {
        if (tree[curr][i] != parent)
        {
            DFS(edges, tree[curr][i], curr);
            A[curr] += A[tree[curr][i]];
            answer += abs(A[tree[curr][i]]);
            A[tree[curr][i]] = 0;
        }        
    }
}
long long solution(vector<int> a, vector<vector<int>> edges)
{    
    for (size_t i = 0; i < a.size(); i++)
    {
        A.push_back((long long)a[i]);
        answer += a[i];
    }
    if (answer != 0) return -1;    
    tree.resize(a.size());
    for (size_t i = 0; i < edges.size(); ++i)
    {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    DFS(edges, 0, 0);
    return answer;
}
int main()
{
    vector<int> a = {0, 0, 0, 0, 0};
    vector<vector<int>> edges = { {0, 1}, {3, 4}, {2, 3}, {0, 3} };

    std::cout << solution(a, edges);
}