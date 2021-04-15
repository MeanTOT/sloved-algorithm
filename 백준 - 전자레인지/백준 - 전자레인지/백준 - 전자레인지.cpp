#include <iostream>
using namespace std;

int T = 0;
int secondes[3] = { 300, 60, 10 };
int answer[3] = { 0, 0, 0 };
void solution()
{
    for (int i = 0; i < 3; i++)
    {
        while (T - secondes[i] >= 0)
        {
            T -= secondes[i];
            answer[i]++;
        }
    }
}
int main()
{
    cin >> T;
    int t = T;
    while (t >= 10)
        t %= 10;
    if (t == 0)
    {
        solution();
        cout << answer[0] << " " << answer[1] << " " << answer[2];
    }
    else
        cout << -1 << endl;
}