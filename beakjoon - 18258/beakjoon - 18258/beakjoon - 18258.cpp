#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int value = 0;
    Node* next = nullptr;
};

class Queue
{
    Node* top = nullptr;
    Node* last = nullptr;
    int size = 0;
public:
    void Push(int value)
    {
        Node* newNode = new Node;
        newNode->value = value;

        if (top == nullptr)
        {
            top = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }

        size++;
    }

    void Pop()
    {        
        if (size > 0)
        {
            Node* temp = top;
            cout << top->value << "\n";
            top = top->next;
            delete(temp);
            size--;
        }          
        else
        {
            cout << -1 << "\n";
        }                
    }

    void Size()
    {
        cout << size << "\n";
    }

    void Empty()
    {
        if (size == 0) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    void Front()
    {
        if (size != 0)
            cout << top->value << "\n";
        else
            cout << -1 << "\n";
    }

    void Back()
    {
        if (size != 0)
            cout << last->value << "\n";
        else
            cout << -1 << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N = 0, val = 0;
    cin >> N;

    string oper = "";
    Queue _queue;
    for (int i = 0; i < N; ++i)
    {
        cin >> oper;
        if (oper == "push")
        {
            cin >> val;
            _queue.Push(val);
        }
        if (oper == "front")
        {
            _queue.Front();
        }
        if (oper == "pop")
        {
            _queue.Pop();
        }
        if (oper == "size")
        {
            _queue.Size();
        }
        if (oper == "empty")
        {
            _queue.Empty();
        }
        if (oper == "back")
        {
            _queue.Back();
        }
    }
}