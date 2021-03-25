#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    sort(people.begin(), people.end());
        
    int startJindex = people.size() - 1;
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = startJindex; j >= 0; j--)
        {
            if (j <= i)
            {
                answer += startJindex - j + 1;
                return answer;
            }

            if (people[i] + people[j] <= limit)
            {
                answer += startJindex - j + 1;
                startJindex = j - 1;

                if (j == i + 1)
                    return answer;
                else
                    break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> people = { 70, 50, 80, 50 };
    cout << solution(people, 100);
    return 0;
}
