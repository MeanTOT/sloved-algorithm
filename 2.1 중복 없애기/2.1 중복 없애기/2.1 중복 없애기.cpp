#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    list<int> _list = { 0, 1, 3, 3, 6, 7, 2, 1, 2, 3, 0 };
    set<int> _buffer;
    vector<list<int>::iterator> iterStack;

    for (list<int>::iterator iter = _list.begin(); iter != _list.end(); ++iter)
    {
        auto deleteTarget = _buffer.find(*iter);

        // 원소를 찾았을 때
        if (deleteTarget != _buffer.end())
        {
            iterStack.push_back(iter);            
        }
        else
        {
            _buffer.insert(*iter);
        }
    }

    for (int i = 0; i < iterStack.size(); i++)
    {
        _list.erase(iterStack[i]);
    }

    return 0;
}