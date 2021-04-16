#include <iostream>
#include <vector>
using namespace std;
int L, P, V = 0;
vector<int> answers;
int solution()
{
    int result = 0;
    while (V > 0)
    {
        if (V - L > 0)
        {
            result += L;
            V -= P;
        }
        else
        {
            if (V > 0)
                result += V;
            break;
        }
    }
    return result;
}
int main()
{
    int caseCount = 0;
    while (true)
    {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;
        else
            answers.push_back(solution());            
    }    
    for (int i = 0; i < answers.size(); i++)
    {
        cout << "Case " << ++caseCount << ": " << answers[i] << endl;
    }
}