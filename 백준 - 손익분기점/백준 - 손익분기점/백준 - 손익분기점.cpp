#include <iostream>
using namespace std;
int main()
{
	int A = 0, B = 0, C = 0;
	cin >> A >> B >> C;
	if (B >= C) cout << -1;
	else cout << A / (C - B) + 1;
}