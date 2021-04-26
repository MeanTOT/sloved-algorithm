#include <iostream>
#include <string>
using namespace std;
int result[10] = { 0 };
int main()
{
    int A, B, C = 0;
    cin >> A >> B >> C;
    int N = (A * B * C);
    string Ns = to_string(N);
    for (int i = 0; i < Ns.length(); ++i) result[Ns[i] - 48]++;
    for (int i = 0; i < 10; ++i) printf("%d\n", result[i]);
}