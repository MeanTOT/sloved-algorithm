#include <iostream>
#include <string>
using namespace std;
int main()
{
    string player = "SK";
    int N = 0;
    cin >> N;
    while (true)
    {
        if (N - 3 >= 3) N -= 3;
        else if (N - 3 < 3) N -= 1;

        if (N == 0) break;
        if (player == "SK") player = "CY";
        else if (player == "CY") player = "SK";
    }
    cout << player;
}