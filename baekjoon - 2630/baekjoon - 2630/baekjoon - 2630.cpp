#include <iostream>
using namespace std;
int N = 0, Color = 0, White = 0, Blue = 0;
int ColoredPaper[128][128];

bool IsAllSameColor(int x, int y, int size, int& color)
{    
    int startColor = ColoredPaper[y][x];
    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            if (startColor != ColoredPaper[i][j]) return false;
        }
    }
    color = startColor;
    return true;
}

void Solution(int x, int y, int size)
{
    int color = -1;
    if (IsAllSameColor(x, y, size, color))
    {
        if (color == 0) White++;
        else Blue++;
    }
    else
    {
        Solution(x, y, size / 2);
        Solution(x + size / 2, y, size / 2);
        Solution(x, y + size / 2, size / 2);
        Solution(x + size / 2, y + size / 2, size / 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> ColoredPaper[i][j];
        }
    }

    Solution(0, 0, N);

    cout << White << "\n";
    cout << Blue << "\n";
}