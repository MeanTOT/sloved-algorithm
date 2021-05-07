#include <iostream>
#include <vector>
using namespace std;
vector<int> set;

int Find(int n)
{
    if (set[n] == n) return n;
    return set[n] = Find(set[n]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    set[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, m = 0;
    cin >> n >> m;
    set.resize(n + 1);
    for (int i = 1; i <= n; ++i) set[i] = i;
    for (int i = 0; i < m; ++i)
    {
        int oper = 0, a = 0, b = 0;
        cin >> oper >> a >> b;
        if (oper == 1)
        {
            if (Find(a) == Find(b))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        else
            Union(a, b);
    }
}