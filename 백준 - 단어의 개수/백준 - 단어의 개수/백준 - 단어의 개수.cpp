#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    bool isFirst = true;
    int result = 0;
    int N = str.length();
    for (int i = 0; i < N; ++i)
    {
        if (str[i] == ' ') isFirst = true;
        else if (str[i] != ' ' && isFirst)
        {
            isFirst = false;
            result++;
        }        
    }
    cout << result;
}