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


    if (target_i % 3 == 0) target_i -= 2;
    if (target_j % 3 == 0) target_j -= 2;
    while (target_i % 3 != 0) target_i--;
    while (target_j % 3 != 0) target_j--;
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
            target_j -= 3;
        }
    }

    return result;
}

void Solution(int target_i, int target_j, bool& SudokuIsComplete)
{
    if (target_i == 10 && target_j == 1)
    {
        for (int i = 1; i <= 9; ++i)
        {
            int sum = 0;
            for (int j = 1; j <= 9; ++j)
            {
                sum += GameTable[i][j];
            }
            if (sum != 45)
            {
                return;
            }
        }

        SudokuIsComplete = true;
        return;
    }

    if (GameTable[target_i][target_j] == 0)
    {
        vector<bool> Numbers = CreateNumbersVector(target_i, target_j);
        for (int i = 1; i < Numbers.size(); ++i)
        {
            if (Numbers[i] == false && SudokuIsComplete == false)
            {
                GameTable[target_i][target_j] = i;
                if (target_j + 1 == 10)
                {
                    Solution(target_i + 1, 1, SudokuIsComplete);
                }
                else
                {
                    Solution(target_i, target_j + 1, SudokuIsComplete);
                }

                if (SudokuIsComplete == false)
                {
                    GameTable[target_i][target_j] = 0;
                }
            }
        }
    }
    else
    {
        if (target_j + 1 == 10)
        {
            Solution(target_i + 1, 1, SudokuIsComplete);
        }
        else
        {
            Solution(target_i, target_j + 1, SudokuIsComplete);
        }
    }    
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
                bool SudokuIsComplete = false;
                Solution(i, j, SudokuIsComplete);
                break;
            }
        }
    }    
    
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cout << GameTable[i][j] << " ";
        }
        cout << "\n";
    }
}