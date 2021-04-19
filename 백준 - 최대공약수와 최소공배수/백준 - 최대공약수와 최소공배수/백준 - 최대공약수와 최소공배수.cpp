#include <iostream>
using namespace std;
int GCD(int A, int B)
{
    if (B == 0) return A;
    return GCD(B, A % B);
}
int main()
{
    int A, B = 0;
    cin >> A >> B;
    int gdc = 0;
    if (A > B)
        gdc = GCD(A, B);
    else
        gdc = GCD(B, A);
    int lcm = (A * B) / gdc;
    printf("%d\n%d", gdc, lcm);
}