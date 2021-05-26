#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int C = 0;
    cin >> C;
    while (C--)
    {
        int N = 0, M = 0, P = 0, count = 0;
        vector<int> priority;
        queue<int> copys;
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
            cin >> P;
            priority.push_back(P);
            copys.push(P);
        }
        sort(priority.begin(), priority.end());

        while (true)
        {
            if (copys.front() < priority.back())
            {
                while (copys.front() != priority.back())
                {
                    int temp = copys.front();
                    copys.pop();
                    copys.push(temp);
                    if (M == 0) M = copys.size() - 1;
                    else M--;
                }                             

                copys.pop();
                priority.pop_back();
                if (M == 0)
                {
                    count++;
                    cout << count << "\n";
                    break;
                }
                else
                {
                    M--;
                }                
            }
            else
            {
                copys.pop();
                priority.pop_back();                                
                if (M == 0)
                {
                    count++;
                    cout << count << "\n";
                    break;
                }
                else
                {
                    M--;                    
                }                
            }   

            count++;
        }
    }
}