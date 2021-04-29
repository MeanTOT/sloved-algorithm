#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int N = 0;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    while (N--)
    {
        int x = 0;
        cin >> x;
        if (x != 0)
            heap.push(make_pair(abs(x), x));
        else
        {
            if (heap.size() == 0)
            {
                printf("0\n");
                continue;
            }
            printf("%d\n", heap.top().second);
            heap.pop();
        }
    }
}