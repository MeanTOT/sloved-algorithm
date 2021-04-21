#include <iostream>
using namespace std;
int H, M = 0;
int main()
{
    cin >> H >> M;
    int cH = H;
    int cM = 0;
    if (M - 45 < 0) cH = (H + 24 - 1) % 24;
    cM = (M + 60 - 45) % 60;
    cout << cH << " " << cM;
}