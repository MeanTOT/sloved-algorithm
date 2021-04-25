#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "";
    cin >> str;
    char alphabet = 'a';    

    int i, j;
    int N = str.length();
    for (i = 0; i < 26; ++i)
    {
        int result = -1;
        for (j = 0; j < N; ++j)
        {
            if (alphabet == str[j])
            {
                result = j;
                break;
            }
        }
        printf("%d ", result);
        alphabet++;
    }
}