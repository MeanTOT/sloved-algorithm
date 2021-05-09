#include <iostream>
using namespace std;
int main()
{
	int A = 0, B = 0, V = 0;
	cin >> A >> B >> V;
	if ((V - B) % (A - B) == 0) cout << (V - B) / (A - B);
	else cout << (V - B) / (A - B) + 1;
}