#include <iostream>
#include <string>

using namespace std;

string StringCompression(string param1);

int main()
{
    string arg1 = "aabccccaaa";

    cout << StringCompression(arg1);

    return 0;
}

string StringCompression(string param1)
{
    size_t prevLenth = param1.length();
    string result = "";        
    int sameChar = 1;

    for (int i = 0; i < param1.length() - 1; i++)
    {          
        if (sameChar == 1)
            result += param1[i];

        if (param1[i] == param1[i + 1])
        {
            sameChar++;
        }
        else
        {
            result += to_string(sameChar);
            sameChar = 1;
        }
    }

    result += to_string(sameChar);

    if (result.length() > prevLenth)
        return param1;
    else
        return result;
}
