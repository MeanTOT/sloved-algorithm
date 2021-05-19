#include <iostream>
#include <vector>
int GameTable[10][10];
using namespace std;

vector<bool> CreateNumbersVector(int target_i, int target_j)
{
    vector<bool> result(10);

    for (int i = 1; i < 10; ++i)
    {
        if (GameTable[target_i][i] != 0)
            result[GameTable[target_i][i]] = true;
        if (GameTable[i][target_j] != 0)
            result[GameTable[i][target_j]] = true;
    }

    while (target_i / 3 != 0) target_i--;
    while (target_j / 3 != 0) target_j--;
    target_i++;
    target_j++;

    for (int i = 0; i < 9; ++i)
    {
        if (GameTable[target_i][target_j] != 0)
        {
            result[GameTable[target_i][target_j]] = true;
        }

        target_j++;
        if (target_j % 3 == 1)
        {
            target_i++;
        }
    }

    return result;
}

void Solution(int target_i, int target_j)
{
    vector<bool> Numbers = CreateNumbersVector(target_i, target_j);

    int a = 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 1; i <= 9; ++i)
    {        
        for (int j = 1; j <= 9; ++j)
        {
            cin >> GameTable[i][j];
        }
    }


    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            if (GameTable[i][j] == 0)
            {
                Solution(i, j);
                break;
            }
        }
    }
}