#include <iostream>
#include <vector>
using namespace std;
int N = 0, M = 0;
void Solution(vector<int> selected, int select, int remain)
{
    selected.push_back(select);

    if (remain == 0)
    {
        for (int i = 0; i < selected.size(); ++i)
        {
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        Solution(selected, i, remain - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        vector<int> selected;
        Solution(selected, i, M - 1);
    }
}