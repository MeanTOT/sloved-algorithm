#include <iostream>
#include <string>
#include <vector>
using namespace std;
string formula = "";
string GetToken(int& index)
{
    string result = "";
    bool isNumber = false;
    if (formula[index] != '-' && formula[index] != '+')
        isNumber = true;

    if (isNumber)
    {
        while (formula[index] != '-' && formula[index] != '+')
        {
            result += formula[index];
            index++;

            if (index == formula.length())
                break;
        }
        return result;
    }    
    else
    {
        result += formula[index];
        index++;
        return result;
    }
}
int Solution()
{
    string oper = "";
    int sum = 0;
    int index = 0;    
    int number = stoi(GetToken(index));
    vector<int> remain;
    while (index != formula.length())
    {
        oper = GetToken(index);
        if (oper == "-")
        {
            remain.push_back(number);
            number = stoi(GetToken(index));
            if (index == formula.length())
            {
                remain.push_back(number);
                break;
            }
        }
        else
        {
            number += stoi(GetToken(index));

            if (index == formula.length())
                remain.push_back(number);
        }
    }
    if (remain.size() == 0)
        return number;
    int result = remain[0];
    for (int i = 1; i < remain.size(); i++)
    {
        result -= remain[i];
    }
    return result;
}
int main()
{
    cin >> formula;
    cout << Solution();
}