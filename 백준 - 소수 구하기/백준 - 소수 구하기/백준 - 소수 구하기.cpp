#include <iostream>
#include <vector>
#include <memory.h>
#include <math.h>
using namespace std;
int M, N = 0;
vector<int> primes;
bool isPrime(int N)
{
    if (N == 1) return false;
    if (N == 2) return true;
    int sqrtN = (int)sqrt(N);
    for (int i = 2; i <= sqrtN; i++)
        if (N % i == 0) return false;
    return true;
}
int main()
{
    cin >> M >> N;    
    for (int i = M; i <= N; i++)
        if (isPrime(i))
            printf("%d\n", i);
}