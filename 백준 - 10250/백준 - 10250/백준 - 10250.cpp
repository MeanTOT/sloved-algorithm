#include <iostream>
using namespace std;
int main()
{
    int T = 0, H = 0, W = 0, N = 0;
    cin >> T;
    while (T--)
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cin >> H >> W >> N;        
        if ((N % H) == 0) cout << (H * 100) + (N / H) << "\n";
        else cout << ((N % H) * 100) + ((N / H) + 1) << "\n";        
    }
}