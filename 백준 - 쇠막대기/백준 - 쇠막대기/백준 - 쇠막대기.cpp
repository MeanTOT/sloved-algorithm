#include <iostream>
#include <stack>
#include <string>
using namespace std;
string input;
int answer = 0;
int Stack(int& index)
{
    if (index == -1)
    {
        Stack(++index);
        return 0;
    }
    int laser = 0;
    while (input[index] == '(')
    {
        laser += Stack(++index);
    }
    if (input[index - 1] == '(' && input[index] == ')')
    {
        index++;
        return 1;
    }
    if (input[index - 1] == ')' && input[index] == ')')
    {
        index++;
        answer += laser + 1;
    }
    return laser;
}
int main()
{
    cin >> input;
    int index = -1;
    Stack(index);
    cout << answer;
}