#include <iostream>
using namespace std;
int GDC(int A, int B)
{
    if (B == 0) return A;
    return GDC(B, A % B);
}
int main()
{
    int T = 0;
    int A, B = 0;
    cin >> T;
    while (T--)
    {
        cin >> A >> B;
        printf("%d\n", (A * B) / GDC(A, B));
    }
}