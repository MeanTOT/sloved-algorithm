#include <iostream>
#include <vector>
using namespace std;
void Solution(vector<bool>Selected, vector<int> result, int select, int remain)
{
    Selected[select - 1] = true;
    result.push_back(select);

    if (remain <= 0)
    {
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < Selected.size(); ++i)
    {
        if (!Selected[i])
        {
            Solution(Selected, result, i + 1, remain - 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        vector<int> result;        
        vector<bool> Selected(N);
        Solution(Selected, result, i, M - 1);
    }    
}