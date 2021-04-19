#include <iostream>
#include <math.h>
using namespace std;
int M, N = 0;
int main()
{
    cin >> M;
    cin >> N;
    int primeSum = 0;
    int miniPrime = 10001;
    for (int i = M; i <= N; ++i)
    {
        if (i == 1) continue;
        if (i == 2)
        {
            miniPrime = 2;
            primeSum = 2;
            continue;
        }
        int sqrtI = (int)sqrt(i);
        bool isPrime = true;
        for (int j = 2; j <= sqrtI; ++j)
        {
            if (i % j == 0) 
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            miniPrime = min(miniPrime, i);
            primeSum += i;
        }
    }
    if (primeSum == 0) printf("-1");
    else printf("%d\n%d", primeSum, miniPrime);
}