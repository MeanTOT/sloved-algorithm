#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, M = 0;
    vector<int> numbers;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int number = 0;
        cin >> number;
        numbers.push_back(number);
    }

    int result = 0;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N; ++i)
    {
        a = numbers[i];
        for (int j = 0; j < N; ++j)
        {
            if (j == i) continue;
            b = numbers[j];
            for (int k = 0; k < N; ++k)
            {
                if (k == i || k == j) continue;
                c = numbers[k];

                if (a + b + c <= M)
                {
                    result = max(result, a + b + c);
                }
            }
        }
    }

    cout << result;
}