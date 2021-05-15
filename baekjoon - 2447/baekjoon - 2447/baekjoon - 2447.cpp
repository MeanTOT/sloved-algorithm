#include <iostream>
using namespace std;

void Upper(int n)
{
    if (n == 1)
    {
        cout << "*";
        return;
    }
    Upper(n / 3);
    Upper(n / 3);
    Upper(n / 3);
}

void Solution(int n)
{
    Upper(n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0;
    cin >> N;
    Solution(N);
}