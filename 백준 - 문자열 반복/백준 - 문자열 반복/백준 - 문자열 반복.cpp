#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T = 0;
    cin >> T;
    while (T--)
    {
        int R = 0;
        string S;
        cin >> R >> S;
        int N = S.length();
        string result = "";
        for (int i = 0; i < N; ++i)
        {
            string temp(R, S[i]);
            result += temp;
        }
        printf("%s\n", result.c_str());
    }
}