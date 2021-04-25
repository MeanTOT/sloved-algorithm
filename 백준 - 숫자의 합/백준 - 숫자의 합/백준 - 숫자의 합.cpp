#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    string str = "";
    cin >> str;
    int result = 0;
    for (int i = 0; i < str.length(); ++i)
        result += (int)str[i] - 48;
    cout << result;
}