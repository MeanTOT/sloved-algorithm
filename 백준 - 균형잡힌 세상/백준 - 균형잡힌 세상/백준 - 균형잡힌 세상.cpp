#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<string> strVec;
    while (true)
    {
        string str = "";
        getline(cin, str);
        if (str == ".") break;
        strVec.push_back(str);
    }        
    for (int i = 0; i < strVec.size(); ++i)
    {
        stack<char> brackets;
        bool isOK = true;
        for (int j = 0; j < strVec[i].length(); ++j)
        {            
            if (strVec[i][j] == '(' || strVec[i][j] == '[')
            {
                brackets.push(strVec[i][j]);
            }
            else if (strVec[i][j] == ')')
            {
                if (brackets.empty() || brackets.top() != '(')
                {
                    isOK = false;
                    break;
                }
                brackets.pop();
            }
            else if (strVec[i][j] == ']')
            {
                if (brackets.empty() || brackets.top() != '[')
                {
                    isOK = false;
                    break;
                }
                brackets.pop();
            }
        }
        if (!brackets.empty()) printf("no\n");
        else if (isOK) printf("yes\n");
        else printf("no\n");        
    }
}