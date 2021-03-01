#include <iostream>
#include <string>

using namespace std;

bool IsPalindromePersutation(string param);
void ToLower(string& param);
void EraseEmptySpace(string& param);
char PickChar(string& param);

int main()
{
    string arg = "He lived as a devil eh";

    cout << IsPalindromePersutation(arg);

    return 0;
}

bool IsPalindromePersutation(string param)
{
    ToLower(param);    
    EraseEmptySpace(param);

    size_t count = param.length() / 2 + 1;
    for (size_t i = 0; i < count; i++)
    {        
        char pickedChar = PickChar(param);

        size_t foundIndex = param.find(pickedChar);
        if (foundIndex != string::npos)
        {            
            param.erase(foundIndex, 1);
        }

        if (param.length() == 0)
            return true;
    }
	
    return false;
}

void ToLower(string& param)
{
    for (size_t i = 0; i < param.length(); i++)
    {
        param[i] = tolower(param[i]);
    }
}

void EraseEmptySpace(string& param)
{
    size_t index = 0;

    while (true)
    {
        index = param.find(' ');

        if (index == string::npos)
        {
            return;
        }
        else
        {
            param.erase(index, 1);
        }
    }
}

char PickChar(string& param)
{
    char result = param[0];
    param.erase(0, 1);

    return result;
}
