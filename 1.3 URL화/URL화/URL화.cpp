#include <iostream>
#include <string>

using namespace std;

string CreateURL(string param1, int param2);

int main()
{
    string arg1 = "Mr John Smith";
    int arg2 = 13;

    cout << CreateURL(arg1, arg2);

    return 0;
}

string CreateURL(string param1, int param2)
{
    string result;
    string const TOKEN = "%20";

    for (int i = 0; i < param2; i++)
    {        
        if (param1[i] == ' ')
        {
            result += TOKEN;
        }
        else
        {
            result += param1[i];
        }
    }

    return result;
}
