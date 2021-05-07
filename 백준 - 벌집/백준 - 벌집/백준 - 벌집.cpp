#include <iostream>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;

    if (N == 1) cout << 1;
    else
    {
        int count = 1;
        int i = 1;
        while (true)
        {
            count += (i * 6);
            ++i;
            if (count >= N) break;
        }
        cout << i;
    }    
}