#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetFirstNumber(int N, int count)
{
    string result = "";
    string n_s = to_string(N);
    for (int i = 0 ; i < count; i++)
        result += n_s;

    return stoi(result);
}

int solution(int N, int number) 
{
    int answer = 0;
    vector<vector<int>> set(8);
    for (int i = 0; i < set.size(); ++i)
    {
        set[i].push_back(GetFirstNumber(N, i + 1));

        if (set[i][0] == number)
            return i + 1;

        int l = i - 1;
        for (int j = 0; j < i; ++j)
        {            
            for (int k = 0; k < set[j].size(); ++k)
            {
                for (int m = 0; m < set[l].size(); ++m)
                {
                    int sum = set[j][k] + set[l][m];
                    int sub = set[j][k] - set[l][m];
                    int mul = set[j][k] * set[l][m];

                    if (sum == number || sub == number || mul == number)
                        return i + 1;

                    set[i].push_back(sum);
                    set[i].push_back(sub);
                    set[i].push_back(mul);                    
                    
                    if (set[l][m] != 0)
                    {
                        int div = set[j][k] / set[l][m];
                        if (div == number)
                            return i + 1;
                        set[i].push_back(set[j][k] / set[l][m]);
                    }
                }
            }

            --l;
        }
    }

    return -1;
}

int main()
{
    cout << solution(5, 12);

    return 0;
}