#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> strs;

bool comp(string& a, string& b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }

    return a.length() < b.length();
}

int main()
{
    int N = 0;
    cin >> N;
    while (N--)
    {
        string temp = "";
        cin >> temp;
        strs.push_back(temp);
    }

    if (strs.size() == 1)
        cout << strs[0] << "\n";
    else
    {
        sort(strs.begin(), strs.end(), comp);
        cout << strs[0] << "\n";
        for (int i = 1; i < strs.size(); ++i)
        {
            if (strs[i] != strs[i - 1])
                cout << strs[i] << "\n";
        }
    }    
}