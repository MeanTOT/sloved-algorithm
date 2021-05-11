#include <iostream>
using namespace std;

int Factorial(int n)
{
    if (n <= 1) return 1;
    return n * Factorial(n - 1);
}
int main()
{
    int N = 0;
    cin >> N;
    cout << Factorial(N);
}