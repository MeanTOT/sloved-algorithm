#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<pair<int, int>> answer;
void Solution(int n, int from, int by, int to)
{
    if (n == 0) return;
    Solution(n - 1, from, to, by);    
    answer.push_back(make_pair(from, to));
    Solution(n - 1, by, from ,to);
}

int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    Solution(N, 1, 2, 3);

    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i].first << " " << answer[i].second << "\n";
    }
}