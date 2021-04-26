#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
string s = "";
bool Comp(int i, int j)
{	
	return strcmp(s.c_str() + i, s.c_str() + j) < 0;
}
int main()
{
	vector<int> perm;
	cin >> s;
	for (size_t i = 0; i < s.length(); ++i) perm.push_back(i);
	sort(perm.begin(), perm.end(), Comp);	
}