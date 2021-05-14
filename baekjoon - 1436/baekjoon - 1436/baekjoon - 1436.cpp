#include <iostream>
#include <string>
using namespace std;
int N = 0;
int DeadNumber = 666;
bool IsDeadNumber(int deadNumber)
{
    string num = to_string(deadNumber);
    
    for (int i = 0; i < num.size() - 2; ++i)
    {
        if (num[i] == '6' && num[i + 1] == '6' && num[i + 2] == '6')
        {
            return true;
        }
    }

    return false;
}
int main()
{    
    cin >> N;    
    int index = 0;   
    while (true)
    {
        if (IsDeadNumber(DeadNumber))
        {
            N--;
            if (N == 0) break;
        }
        DeadNumber++;
    }

    cout << DeadNumber;
}