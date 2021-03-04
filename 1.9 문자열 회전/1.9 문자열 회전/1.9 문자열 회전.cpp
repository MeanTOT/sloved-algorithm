#include <iostream>
#include <string>

using namespace std;

bool IsSubstring(string str1, string str2);

int main()
{
    string str1 = "erbottlewat";
    string str2 = "waterbottle";

    cout << IsSubstring(str1, str2);

    return 0;
}

// x = erbottle
// y = wat
// str2 = yx
// xyxy = erbottlewaterbottlewat
bool IsSubstring(string str1, string str2)
{
    string xyxy = str1 + str1;
    return xyxy.find(str2) != string::npos;
}
