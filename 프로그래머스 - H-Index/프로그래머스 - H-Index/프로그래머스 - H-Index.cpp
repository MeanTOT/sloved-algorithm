#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) 
{
    sort(citations.begin(), citations.end());    

    int answer = 0;
    int hIndex = citations.size() + 1;
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= --hIndex)
        {
            answer = hIndex;
            break;
        }
    }
    return answer;
}

int main()
{
    vector<int> citations = { 3, 0, 6, 1, 5 };
    cout << solution(citations);

    return 0;
}