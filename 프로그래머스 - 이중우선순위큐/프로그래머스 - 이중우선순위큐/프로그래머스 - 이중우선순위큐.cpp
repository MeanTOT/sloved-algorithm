#include <string>
#include <vector>
#include <queue>

using namespace std;

void DoOperation(string operation, vector<int>& queue)
{
    if (operation[0] == 'D')
    {
        if (queue.empty())
            return;

        if (operation[2] == '1')
        {
            make_heap(queue.begin(), queue.end(), less<int>());
            pop_heap(queue.begin(), queue.end(), less<int>());
            queue.pop_back();
        }
        else if (operation[2] == '-')
        {
            make_heap(queue.begin(), queue.end(), greater<int>());
            pop_heap(queue.begin(), queue.end(), greater<int>());
            queue.pop_back();
        }
    }
    else if (operation[0] == 'I')
    {
        queue.push_back(stoi(operation.substr(2)));
    }
}

vector<int> solution(vector<string> operations) 
{
    vector<int> answer;
    vector<int> queue;        

    for (int i = 0; i < operations.size(); i++)
    {
        DoOperation(operations[i], queue);
    }

    if (queue.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        make_heap(queue.begin(), queue.end(), less<int>());        
        answer.push_back(queue[0]);
        make_heap(queue.begin(), queue.end(), greater<int>());
        answer.push_back(queue[0]);
    }

    return answer;
}

int main()
{
    vector<string> opers = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
    solution(opers);

    return 0;
}