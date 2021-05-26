#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, K = 0;
    cin >> N >> K;
    queue<int> circle;

    for (int i = 1; i <= N; ++i) circle.push(i);
    int remain = K;


    cout << "<";
    while (circle.size() != 1)
    {
        if (remain == 1)
        {
            cout << circle.front() << ", ";
            circle.pop();
            remain = K;
        }
        else
        {
            remain--;
            int temp = circle.front();
            circle.pop();
            circle.push(temp);
        }
    }
    cout << circle.front() << ">";
}