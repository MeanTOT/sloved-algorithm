#include <iostream>
#include <vector>
using namespace std;
int k = 0;
int n = 0;
vector<vector<int>> apartment;
int solution()
{
    for (int i = 0; i < n; i++)
        apartment[0][i] = i + 1;
    for (int i = 1; i < k + 1; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += apartment[i - 1][j];
            apartment[i][j] = sum;
        }        
    }

    int result = apartment[k][n - 1];
    return result;
}
int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        cin >> k;
        cin >> n;
        apartment.resize(k + 1);
        for (int i = 0; i < k + 1; i++)
            apartment[i].resize(n);
        cout << solution() << endl;
        apartment.clear();
    }
}