#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0, caseNumber = 0, A = 0, B = 0;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> A >> B;
        cout << "Case #" << ++caseNumber << ": " << A + B << "\n";
    }
}