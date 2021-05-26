#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

	int A = 0, B = 0;

	while (true)
	{
		cin >> A >> B;
		if (A == 0 && B == 0) break;

		if (B % A == 0) cout << "factor" << "\n";
		else if (A % B == 0) cout << "multiple" << "\n";
		else cout << "neither" << "\n";
	}
}