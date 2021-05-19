#include <iostream>
#include <vector>
using namespace std;
int N = 0, Answer = 100000000;
vector<vector<int>> abilityMap;

void MakeTeam(vector<bool> team, int select, int remain)
{
    team[select] = true;

    if (remain == 0)
    {        
        int team_1_ability = 0;
        int team_2_ability = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (team[i] == false && team[j] == false)
                {
                    team_1_ability += abilityMap[i][j];
                }
                else if (team[i] == true && team[j] == true)
                {
                    team_2_ability += abilityMap[i][j];
                }
            }            
        }

        Answer = min(Answer, abs(team_1_ability - team_2_ability));
        return;
    }

    for (int i = select + 1; i < N; ++i)
    {
        if (team[i] == false)
        {
            MakeTeam(team, i, remain - 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    abilityMap.resize(N);
    for (int i = 0; i < N; ++i)
    {
        abilityMap[i].resize(N);
        for (int j = 0; j < N; ++j)
        {
            cin >> abilityMap[i][j];
        }
    }

    for (int i = 0; i <= N / 2; ++i)
    {
        vector<bool> team(N);
        MakeTeam(team, i, N / 2 - 1);
    }

    cout << Answer;
}