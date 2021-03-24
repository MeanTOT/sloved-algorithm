#include <string>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

set<int> primeNumbers;

bool IsPrimeNumber(int value)
{
    if (value == 1)
        return false;

    for (int i = 2; i <= sqrt(value); i++)
    {
        if (value % i == 0)
            return false;
    }

    return true;
}

void MakeNumber(string number, vector<char> pages, int eraseIndex)
{    
    number += pages[eraseIndex];
    pages.erase(pages.begin() + eraseIndex);

    int numberInt = stoi(number);
    if (IsPrimeNumber(numberInt))
    {
        primeNumbers.insert(numberInt);
    }

    for (int i = 0; i < pages.size(); i++)
    {
        MakeNumber(number, pages, i);
    }
}

int solution(string numbers) 
{
    int answer = 0;
    vector<char> pages;
    for (int i = 0; i < numbers.size(); i++)
    {
        pages.push_back(numbers[i]);
    }    
    
    string number;
    for (int i = 0; i < pages.size(); i++)
    {
        if (pages[i] == '0')
            continue;

        MakeNumber(number, pages, i);
    }
    
    answer = primeNumbers.size();
    return answer;
}

int main()
{
    solution("011");

	return 0;
}