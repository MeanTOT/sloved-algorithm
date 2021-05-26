#include <iostream>
using namespace std;

int GCD(int A, int B)
{
    if (B == 0) return A;
    return GCD(B, A % B);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N = 0, radius = 0, criterion = 0;
    cin >> N;
    cin >> criterion;
    for (int i = 0; i < N - 1; ++i)
    {        
        cin >> radius;

        int gcd = GCD(radius, criterion);

        cout << criterion / gcd << "/" << radius / gcd << "\n";
    }
}