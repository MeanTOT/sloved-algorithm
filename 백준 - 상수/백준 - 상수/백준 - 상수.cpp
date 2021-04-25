#include <iostream>
#include <algorithm>    
#include <string>
using namespace std;

int main()
{
    string A, B = "";
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int iA = stoi(A);
    int iB = stoi(B);
    if (iA > iB) cout << iA;
    else cout << iB;
}