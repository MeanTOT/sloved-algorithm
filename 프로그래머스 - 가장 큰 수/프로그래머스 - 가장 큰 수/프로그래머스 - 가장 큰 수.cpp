#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2)
{
    int currentIndex = 0;
    while (s1.length() < 4)    
        s1 += s1[currentIndex++];            

    currentIndex = 0;
    while (s2.length() < 4)    
        s2 += s2[currentIndex++];

    return s1 > s2;
}

string solution(vector<int> numbers) 
{
    vector<string> orderdNumbers;
    for (int i = 0; i < numbers.size(); i++)
        orderdNumbers.push_back(to_string(numbers[i]));

    sort(orderdNumbers.begin(), orderdNumbers.end(), comp);

    if (orderdNumbers[0] == "0")
        return "0";

    string answer = "";
    for (int i = 0; i < orderdNumbers.size(); i++)
        answer += orderdNumbers[i];

    return answer;
}

int main()
{
    vector<int> numbers = { 999, 998, 9};
    cout << solution(numbers);

    return 0;
}