#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book)
{
    set<string> phoneNumbers;
    for (int i = 0; i < phone_book.size(); i++)
    {
        phoneNumbers.insert(phone_book[i]);        
    }

    set<string>::iterator iter;
    for (iter = phoneNumbers.begin(); iter != phoneNumbers.end(); ++iter)
    {
        for (int i = 1; i < (*iter).length(); i++)
        {
            if (phoneNumbers.find((*iter).substr(0, i)) != phoneNumbers.end())
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<string> phoneBook = { "12", "123", "1235", "567", "88" };

    cout << solution(phoneBook);

    return 0;
}
