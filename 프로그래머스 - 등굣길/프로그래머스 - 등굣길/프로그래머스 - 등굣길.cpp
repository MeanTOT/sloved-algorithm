#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int map[101][101] = { 0 };
    int const PUDDLE = -1;

    for (int i = 0; i < puddles.size(); i++)
    {
        map[puddles[i][1]][puddles[i][0]] = PUDDLE;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                map[i][j] = 1;
            else if (map[i][j] == PUDDLE)
                map[i][j] = 0;
            else
                map[i][j] = (map[i][j - 1] + map[i - 1][j]) % 1000000007;
        }
    }

    return map[n][m];
}

int main()
{
    vector<vector<int>> puddles = { {2, 2} };
    return 0;
}

//시간복잡도 : O(puddles.size + m*n)
//공간복잡도 : O(1)