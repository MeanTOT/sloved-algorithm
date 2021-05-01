#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int N = 0;
    int Max = -1000001;
    int Min = 1000001;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int number = 0;
        cin >> number;
        if (number > Max) Max = number;
        if (number < Min) Min = number;        
    }
    cout << Min << " " << Max << endl;
}