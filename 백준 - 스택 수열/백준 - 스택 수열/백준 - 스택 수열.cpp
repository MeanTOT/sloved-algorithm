#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;    
    int max = 0;
    stack<int> _stack;
    vector<char> answer;
    while (N--)
    {
        int num = 0;
        cin >> num;        
        if (num > max)
        {
            for (int i = max + 1; i <= num; i++)
            {
                _stack.push(i);
                answer.push_back('+');
            }
            max = num;
        }
        else if (_stack.top() != num)
        {
            printf("NO");
            return 0;
        }
        _stack.pop();
        answer.push_back('-');
    }
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%c\n", answer[i]);
    }
}