#include <iostream>
#include <string>
#include <vector>

using namespace std;


string SingleSolution(string s)
{
    return s;
}

vector<string> solution(vector<string> s) 
{
    vector<string> answer;

    for (int i = 0; i < s.size(); ++i)
    {
        answer.push_back(SingleSolution(s[i]));
    }
    return answer;
}

int main()
{
    vector<string> result = solution({ "1011110","01110","101101111010" });

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }
}
