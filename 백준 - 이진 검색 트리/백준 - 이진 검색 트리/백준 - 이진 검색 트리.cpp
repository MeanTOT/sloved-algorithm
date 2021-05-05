#include <iostream>
#include <vector>
using namespace std;
vector<int> in;
void Post(int start, int end)
{
    if (start <= end)
    {
        bool noRight = true;
        for (int i = start + 1; i <= end; ++i)
        {
            if (in[start] < in[i])
            {
                Post(start + 1, i - 1);
                Post(i, end);
                noRight = false;
                break;
            }
        }
        if (noRight) Post(start + 1, end);
        cout << in[start] << " ";
    }        
}
int main()
{
    ios::sync_with_stdio(false);
    int n = 0;
    while (cin >> n) in.push_back(n);
    Post(0, in.size() - 1);
}