#include <iostream>
using namespace std;
int N = 0;
char video[64][64];
bool IsAllSameColor(int x, int y, int size, int& color)
{
    int startColor = video[y][x];
    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            if (startColor != video[i][j])
                return false;
        }
    }

    color = startColor;
    return true;
}

void Solution(int x, int y, int size)
{
    int color = 0;
    if (IsAllSameColor(x, y, size, color))
    {
        cout << color - '0';
        return;
    }

    cout << "(";
    Solution(x, y, size / 2);
    Solution(x + size / 2, y, size / 2);
    Solution(x, y + size / 2, size / 2);
    Solution(x + size / 2, y + size / 2, size / 2);
    cout << ")";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> video[i][j];
        }
    }
    Solution(0, 0, N);
}