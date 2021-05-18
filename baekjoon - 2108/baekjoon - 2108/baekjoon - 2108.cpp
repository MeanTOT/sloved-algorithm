#include <iostream>
#include <algorithm>
#include <memory.h>
#define ARR_SIZE 500001
#define NUM_SIZE 8002
using namespace std;
int N;
int arr[ARR_SIZE];
int AllSum = 0;
int appearCount[NUM_SIZE];

int main()
{
    cin >> N;
    memset(appearCount, 0, sizeof(appearCount));
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        AllSum += arr[i]; 
        appearCount[arr[i] + 4001]++;
    }

    sort(arr + 1, arr + N + 1);    
    cout << fixed;
    cout.precision(0);
    cout << AllSum / (double)N << "\n";
    cout << arr[N / 2 + 1] << "\n";

    int maxAppearIndex = 0;
    int maxAppearSecondeIndex = 0;
    int maxAppearNum = 0;
    bool isManySameCount = false;
    for (int i = 1; i < 8002; ++i)
    {
        if (appearCount[i] != 0)
        {
            if (appearCount[i] > maxAppearNum)
            {
                maxAppearNum = appearCount[i];
                maxAppearIndex = i - 4001;
                isManySameCount = false;
            }
            else if (appearCount[i] == maxAppearNum)
            {                
                if (maxAppearIndex > i - 4001)
                {                
                    maxAppearIndex = i - 4001;
                }
                else
                {
                    if (!isManySameCount)
                    {
                        maxAppearSecondeIndex = i - 4001;
                    }
                }

                isManySameCount = true;
            }
        }        
    }

    if (isManySameCount)
    {
        cout << maxAppearSecondeIndex << "\n";
    }
    else
    {
        cout << maxAppearIndex << "\n";
    }

    cout << arr[N] - arr[1] << "\n";
}