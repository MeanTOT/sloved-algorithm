#include <iostream>

using namespace std;

void DrawLine(char screen[], int width, int x1, int x2, int y)
{
    for (int i = ((y * width) + x1); i < (y * width) + x2; i++)
    {
        screen[i] = 1;
    }
}

int main()
{
    char screen[64];
    fill_n(screen, 64, 0);

    DrawLine(screen, 8, 2, 6, 4);

    for (int i = 0; i < 64; i++)
    {
        cout << (int)screen[i];

        if ((i + 1) % 8 == 0)
        {
            cout << endl;
        }
    }

    return 0;
}
