#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, num = 0;
    priority_queue<int, vector<int>> q1; // max
    priority_queue<int, vector<int>, greater<int>> q2; // min
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;

        if (q1.size() == q2.size()) q1.push(num);
        else q2.push(num);

        if (!q1.empty() && !q2.empty() && q1.top() > q2.top())
        {
            int temp1 = q1.top(); q1.pop();
            int temp2 = q2.top(); q2.pop();
            q1.push(temp2);
            q2.push(temp1);
        }

        cout << q1.top() << "\n";
    }
}