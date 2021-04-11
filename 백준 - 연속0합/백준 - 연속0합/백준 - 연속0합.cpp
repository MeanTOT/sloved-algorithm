#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N = 0;
vector<int> numbers;
int MaxNumber = -1001;
int cache[100000];
//int dp(int start, int end)
//{
//    if (start == end)
//        return numbers[start];
//
//    int half = (start + end) / 2;
//    int result1 = dp(start, half);
//    int result2 = dp(half + 1, end);
//    int result3 = result1 + result2;
//    MaxNumber = max(max(result1, result2), result3);
//    return result3;
//}
int dp(int previsou, int index)
{
    if (index == numbers.size()) return 0;    
    MaxNumber = max(MaxNumber, previsou + numbers[index]);
    dp(previsou + numbers[index], index + 1);
}
int solution()
{
    /*for (int i = 0; i < N; i++)
    {
        MaxNumber = dp(0, i);
    }*/
    cache[0] = numbers[0] + numbers[1];
    MaxNumber = cache[0];
    for (int i = 1; i < N - 1; i++)
    {
        cache[i] = cache[i - 1] + numbers[i + 1];
        MaxNumber = max(MaxNumber, cache[i]);
    }
    int sub = 0;
    for (int i = 0; i < N - 2; i++)
    {
        sub += numbers[i];
        for (int j = i + 1; j < N - 1; j++)
        {
            MaxNumber = max(MaxNumber, cache[j] - sub);
        }
        MaxNumber = max(MaxNumber, numbers[i]);
    }
    MaxNumber = max(MaxNumber, numbers[N - 2]);
    MaxNumber = max(MaxNumber, numbers[N - 1]);
    return MaxNumber;
}
int main()
{
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    cout << solution();
}