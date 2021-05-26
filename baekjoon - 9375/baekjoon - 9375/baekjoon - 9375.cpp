#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int N = 0;
map<string, vector<string>> clothes;

int Solution()
{
    int ret = 1;
    for (auto iter = clothes.begin(); iter != clothes.end(); ++iter)
    {
        ret *= (iter->second.size() + 1);
    }
    return ret - 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int C = 0;
    cin >> C;
    while (C--)
    {
        clothes.clear();
        cin >> N;
        string  name = "", parts = "";
        for (int i = 0; i < N; ++i)
        {
            cin >> name >> parts;
            clothes[parts].push_back(name);
        }        
        cout << Solution() << "\n";
    }
}