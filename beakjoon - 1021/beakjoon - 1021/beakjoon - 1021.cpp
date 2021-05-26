#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N = 0, M = 0, C = 0;
deque<int> circleQueue;
vector<int> candidates;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);    
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        circleQueue.push_back(i);
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> C;
        candidates.push_back(C);
    }

    int ret = 0;
    for (int i = 0; i < M; ++i)
    {
        int left = candidates[i] - 1;
        int right = circleQueue.size() - candidates[i] + 1;

        if (left <= right)
        {
            ret += left;
            for (int i = 0; i < left; ++i)
            {
                int temp = circleQueue.front();
                circleQueue.pop_front();
                circleQueue.push_back(temp);
            }

            for (int j = i + 1; j < M; ++j)
            {
                candidates[j] -= left;
                if (candidates[j] <= 0)
                {
                    candidates[j] = circleQueue.size() + candidates[j];
                }
            }

            circleQueue.pop_front();

            for (int j = i + 1; j < M; ++j)
            {
                candidates[j] -= 1;
            }
        }
        else
        {
            ret += right;
            for (int i = 0; i < right; ++i)
            {
                int temp = circleQueue.back();
                circleQueue.pop_back();
                circleQueue.push_front(temp);
            }

            for (int j = i + 1; j < M; ++j)
            {
                candidates[j] += right;
                if (candidates[j] > circleQueue.size()) candidates[j] -= circleQueue.size();
            }

            circleQueue.pop_front();

            for (int j = i + 1; j < M; ++j)
            {
                candidates[j] -= 1;
            }
        }
    }
    cout << ret;
}