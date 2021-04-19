#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N = 0;
vector<int> numbers;
int solution()
{
    int result = 0;    
    for (int i = 0; i < N; ++i)
    {
        if (numbers[i] == 1) continue;
        if (numbers[i] == 2)
        {
            result++;
            continue;
        }
        bool isPrime = true;
        for (int j = 2; j <= (int)sqrt(numbers[i]); ++j)
        {
            if (numbers[i] % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime) result++;
    }
    return result;
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