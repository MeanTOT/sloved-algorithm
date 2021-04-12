#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N = 0;
vector<int> numbers;
int MaxNumber = -1001;
int cache[100000];
int dp(int start)
{   
    int& result = cache[start];
    if (result != -370546199) return result;
    result = max(numbers[start], numbers[start] + dp(start + 1));
    return result;
}
int solution()
{
    if (N == 1) return numbers[0];
    int result = numbers[N - 1];
    cache[N - 1] = numbers[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        result = max(result, dp(i));
    }
    return result;
}
int main()
{
    cin >> N;
    numbers.resize(N);
    memset(cache, 1001, sizeof(cache));
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    cout << solution();
}