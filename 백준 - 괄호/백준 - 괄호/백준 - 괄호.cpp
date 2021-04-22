#include <iostream>
#include <stack>
#include <string>
using namespace std;
string solution(string& vps)
{
    stack<char> token;
    for (int i = 0; i < vps.length(); ++i)
    {
        if (vps[i] == '(') token.push(vps[i]);
        else if (vps[i] == ')') if (token.empty()) return "NO";
            else token.pop();
    }
    if (!token.empty()) return "NO";
    return "YES";
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 0;
    cin >> T;
    while (T--)
    {
        string vps = "";
        cin >> vps;
        cout << solution(vps) << endl;
    }
}