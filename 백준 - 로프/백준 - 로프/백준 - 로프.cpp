#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
vector<int> weights;
int Solution()
{
    sort(weights.begin(), weights.end(), greater<int>());
    int result = weights[0];    
    for (int i = 1; i < weights.size(); i++)
    {
        int lopeCount = (i + 1);
        if (result <= weights[i] * lopeCount)
            result = weights[i] * lopeCount;
    }
    return result;
}
int main()
{
    cin >> N;
    weights.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
    }
    cout << Solution();
}