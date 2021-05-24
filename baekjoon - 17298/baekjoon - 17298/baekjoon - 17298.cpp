#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;
int N = 0;
int arr[1000000];
int answer[1000000];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    memset(answer, -1, sizeof(answer));
    stack<int> _stack;
    _stack.push(arr[N - 1]);

    for (int i = N - 2; i >= 0; --i)
    {
        if (arr[i] < _stack.top())
        {
            answer[i] = _stack.top();
            _stack.push(arr[i]);
        }
        else
        {
            _stack.pop();
            while (true)
            {
                if (_stack.empty())
                {
                    _stack.push(arr[i]);
                    break;
                }

                if (arr[i] < _stack.top())
                {
                    answer[i] = _stack.top();
                    _stack.push(arr[i]);
                    break;
                }

                _stack.pop();
            }
        }
    }
    
    for (int i = 0; i < N; ++i) cout << answer[i] << " ";
}