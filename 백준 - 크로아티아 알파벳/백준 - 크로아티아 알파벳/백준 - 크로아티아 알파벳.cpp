#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	set<string> tlans;
	tlans.insert("c=");
	tlans.insert("c-");
	tlans.insert("dz=");
	tlans.insert("d-");
	tlans.insert("lj");
	tlans.insert("nj");
	tlans.insert("s=");
	tlans.insert("z=");
	string S = "";	
	cin >> S;
	int index = 0;
	int N = S.length();
	int result = 0;
	while (index < N)
	{
		string comp = S.substr(index, 2);
		if (tlans.find(comp) != tlans.end()) index += 2;
		else
		{
			if (comp == "dz" && S[index + 2] == '=') index += 3;
			else index += 1;
		}
		++result;
	}
	cout << result;
}