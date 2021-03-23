#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int GetNextScoville(vector<int>& scoville)
{
    unsigned int result = scoville.front();
    pop_heap(scoville.begin(), scoville.end(), greater<int>());
    scoville.pop_back();
    return result;
}

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    make_heap(scoville.begin(), scoville.end(), greater<int>());    

    while (scoville[0] < K)
    {
        unsigned int firstScoville = GetNextScoville(scoville);
        unsigned int secondeScoville = GetNextScoville(scoville);

        unsigned int newScoville = firstScoville + (secondeScoville * 2);

        scoville.push_back(newScoville);
        push_heap(scoville.begin(), scoville.end(), greater<int>());
        answer++;

        if (scoville.size() == 1)
        {
            break;
        }
    }

    if (scoville.size() == 1 && scoville.front() < K)
        return -1;

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    cout << solution(scoville, 10000);

    return 0;
}