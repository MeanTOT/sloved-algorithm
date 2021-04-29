#include <iostream>
using namespace std;
int main()
{
    int A, B = 0;
    cin >> A;
    cin >> B;

    cout << (B % 10) * A << endl;
    cout << ((B / 10) % 10) * A << endl;
    cout << (B / 100) * A << endl;
    cout << B * A << endl;
}