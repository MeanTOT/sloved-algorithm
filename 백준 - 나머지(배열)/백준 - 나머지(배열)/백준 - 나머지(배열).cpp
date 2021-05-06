#include <iostream>
#include <set>
using namespace std;
int main()
{
	int N = 0;
	set<int> _set;
	for (int i = 0; i < 10; ++i)
	{
		cin >> N;
		if (_set.find(N % 42) == _set.end()) _set.insert(N % 42);		
	}
	cout << _set.size();
}