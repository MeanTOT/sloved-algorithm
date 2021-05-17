#include <iostream>
using namespace std;

void Solution(int i, int j, int n)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
    {
        cout << " ";
    }
    else
    {
        if (n / 3 == 0)
        {
            cout << "*";
        }
        else
        {
            Solution(i, j, n / 3);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Solution(i, j, N);
        }
        cout << "\n";
    }
}