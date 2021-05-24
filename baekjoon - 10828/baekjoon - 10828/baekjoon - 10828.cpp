#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int value = 0;
    Node* next = nullptr;
};

class Stack
{
    Node* top = nullptr;
    int size = 0;

private:
    void Clear()
    {
        while (top != nullptr)
        {
            this->Pop();
        }
    }
public:
    void Push(int value)
    {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = top;        
        top = newNode;
        size++;
    }

    void Pop()
    {

        if (size > 0)
        {
            Node* temp = top;
            temp = top->next;
            cout << top->value << "\n";
            delete(top);
            top = nullptr;
            top = temp;
            size--;
        }        
        else
        {
            cout << -1 << "\n";
        }
    }

    int Size()
    {
        return size;
    }

    bool Empty()
    {
        if (size != 0) return false;
        return true;
    }

    void Top()
    {
        if (Empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << top->value << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Stack _stack;
    int N = 0;
    cin >> N;
    while(N--)
    {
        string oper = "";
        cin >> oper;

        if (oper == "push")
        {
            int val = 0;
            cin >> val;
            _stack.Push(val);
        }
        else if (oper == "pop")
        {
            _stack.Pop();
        }
        else if (oper == "size")
        {
            cout << _stack.Size() << "\n";
        }
        else if (oper == "empty")
        {
            cout << _stack.Empty() << "\n";
        }
        else if (oper == "top")
        {
            _stack.Top();
        }
    }
}