#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, string> parent;
unordered_map<string, int> network_size;
string Find(string& u)
{
	if (u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}

void Union(string& u, string& v)
{
	u = Find(u);
	v = Find(v);    

	if (u == v) return;    

    int& u_size = network_size[u];
    int& v_size = network_size[v];
    if (u_size == 0) u_size = 1;
    if (v_size == 0) v_size = 1;
    int newSize = u_size + v_size;
    u_size = newSize;
    v_size = newSize;
    
	parent[u] = v;        
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    cin >> N;
    while (N--)
    {
        int F = 0;
        cin >> F;
        string f1 = "", f2 = "";
        parent.clear();
        network_size.clear();
        for (int i = 0; i < F; ++i)
        {
            cin >> f1 >> f2;

            if (parent.find(f1) == parent.end()) parent[f1] = f1;
            if (parent.find(f2) == parent.end()) parent[f2] = f2;

            Union(f1, f2);            
            cout << max(network_size[f1], network_size[f2]) << "\n";
        }
    }
}