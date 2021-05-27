#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 0, N = 0;    
    cin >> T;
    while (T--)
    {
        string opers = "", arr = "";
        vector<int> numbers;
        cin >> opers;
        cin >> N;
        cin >> arr;

        deque<string> _deque;
        string number = "";
        for (int i = 1; i < arr.size(); ++i)
        {            
            if (arr[i] == ',' || arr[i] == ']')
            {
                if (number != "")
                {
                    _deque.push_back(number);
                    number = "";
                }                
            }
            else
            {
                number += arr[i];
            }
        }

        bool isError = false;
        bool reversed = false;
        for (int i = 0; i < opers.length(); ++i)
        {
            if (opers[i] == 'R')
            {
                if (!reversed) reversed = true;
                else reversed = false;
            }
            else
            {
                if (_deque.empty())
                {
                    cout << "error" << "\n";
                    isError = true;
                    break;
                }

                if (reversed)
                {                    
                    _deque.pop_back();                   
                }
                else
                {
                    _deque.pop_front();
                }                
            }
        }


        if (!isError)
        {
            if (reversed)
            {
                reverse(_deque.begin(), _deque.end());
            }

            cout << "[";
            while (!_deque.empty())
            {
                cout << _deque.front();
                if (_deque.size() != 1) cout << ",";
                _deque.pop_front();
            }
            cout << "]\n";
        }
    }
}