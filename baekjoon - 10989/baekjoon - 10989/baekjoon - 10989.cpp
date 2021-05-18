#include <iostream>
#include <memory.h>
using namespace std;
int N = 0;
#define NUM_SIZE 10001
int appearCount[NUM_SIZE];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    memset(appearCount, 0, sizeof(appearCount));
    for (int i = 1; i <= N; ++i)
    {
        int temp = 0;
        cin >> temp;
        appearCount[temp]++;
    }

    for (int i = 1; i < NUM_SIZE; ++i)
    {
        appearCount[i] = appearCount[i - 1] + appearCount[i];
    }

    for (int i = 1; i < NUM_SIZE; ++i)
    {
        for (int j = 0; j < appearCount[i] - appearCount[i - 1]; ++j)
        {
            cout << i << "\n";
        }
    }
}