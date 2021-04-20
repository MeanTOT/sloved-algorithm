#include <iostream>
#include <math.h>
using namespace std;
int number = 0;
int solution()
{
    int result = 0;
    for (int i = number + 1; i <= number * 2; ++i)
    {
        bool isPrime = true;
        int sqrtNumber = (int)sqrt(i);
        for (int j = 2; j <= sqrtNumber; ++j)
        {
            if (i % j == 0)
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
    while (true)
    {
        cin >> number;
        if (number == 0) break;
        cout << solution() << endl;
    }
}