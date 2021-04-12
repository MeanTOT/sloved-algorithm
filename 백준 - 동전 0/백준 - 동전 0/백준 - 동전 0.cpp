#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N = 0;
int K = 0;
vector<int> A;
int solution()
{
    int result = 0;
    int currentValue = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] <= K)
        {
            while (currentValue + A[i] <= K)
            {
                currentValue += A[i];
                result++;
            }
        }        

        if (currentValue == K)
            return result;
    }

    return result;
}
int main()
{
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << solution();
}