#include <iostream>
#include <string>
using namespace std;

int main()
{
    int cache[26] = { 0 };
    string S = "";
    cin >> S;
    int N = S.length();    
    char result = 0;
    int maxCount = 0;
    int sameCount = 0;
    for (int i = 0; i < N; ++i)
    {
        char c = toupper(S[i]);
        ++cache[(int)c - 65];
        if (cache[(int)c - 65] > maxCount)
        {
            result = c;
            maxCount = cache[(int)c - 65];
            sameCount = 0;
        }
        else if (cache[(int)c - 65] == maxCount) sameCount++;
    }
    if (sameCount == 0)
        cout << result;
    else
        cout << "?";
}