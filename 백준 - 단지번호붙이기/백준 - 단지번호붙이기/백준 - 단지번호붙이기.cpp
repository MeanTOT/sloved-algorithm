#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int mapSize = 0;
vector<vector<int>> map;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> answers;
int DFS(int here)
{
    visited[here] = true;
    int result = 1;
    for (int i = 0; i < adj[here].size(); ++i)
    {
        int there = adj[here][i];
        if (!visited[there])
            result += DFS(there);
    }    

    return result;
}

int DFSAll()
{
    int result = 0;
    visited = vector<bool>(adj.size(), false);
    for (int i = 0; i < adj.size(); ++i)
    {
        if (!visited[i])
        {            
            int answer = DFS(i);

            if (answer > 1)
            {
                result++;
                answers.push_back(answer);
            }
            if (answer == 1 && map[i / mapSize][i % mapSize])
            {
                result++;
                answers.push_back(1);
            }
        }
    }
    return result;
}
int main()
{
    cin >> mapSize;
    map.resize(mapSize);
    adj.resize(mapSize * mapSize);
    visited.resize(mapSize * mapSize);
    for (int i = 0; i < mapSize; ++i)
    {
        for (int j = 0; j < mapSize; ++j)
        {
            int isHome = 0;
            int a = scanf("%1d", &isHome);
            map[i].push_back(isHome);
        }
    }

    for (int i = 0; i < mapSize; ++i)
    {
        for (int j = 0; j < mapSize; ++j)
        {
            if (map[i][j])
            {
                if (i - 1 >= 0 && map[i - 1][j]) // up
                    adj[i* mapSize + j].push_back((i - 1) * mapSize + j);
                if (i + 1 < mapSize && map[i + 1][j]) // down
                    adj[i * mapSize + j].push_back((i + 1) * mapSize + j);
                if (j - 1 >= 0 && map[i][j - 1]) // left
                    adj[i * mapSize + j].push_back(i * mapSize + j - 1);
                if (j + 1 < mapSize && map[i][j + 1]) // right
                    adj[i * mapSize + j].push_back(i * mapSize + j + 1);
            }
        }
    }

    cout << DFSAll() << endl;
    sort(answers.begin(), answers.end());
    for (int i = 0; i < answers.size(); ++i)
    {
        cout << answers[i] << endl;
    }
}