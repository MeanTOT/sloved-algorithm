#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;
    int result = 0;
    while (N--)
    {        
        string word = "";
        cin >> word;

        set<char> cache;
        bool ischecker = true;
        for (int i = 0; i < word.length(); ++i)
        {
            if (cache.find(word[i]) == cache.end())
            {
                cache.insert(word[i]);

                for (int j = i + 1; i < word.length(); ++j)
                {
                    if (word[j] == word[i])
                        ++i;
                    else
                        break;
                }
            }
            else
            {
                ischecker = false;
                break;
            }
        }
        if (ischecker) result++;        
    }
    cout << result;
}