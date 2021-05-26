#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int value = 0;
    Node* next = nullptr;
};

class MyDeque
{
private:
    Node* front = nullptr;
    Node* back = nullptr;
    int size = 0;
public:
    void Push_front(int val)
    {
        Node* newNode = new Node;
        newNode->value = val;        
        if (front == nullptr)
        {
            front = newNode;
            if (back == nullptr)
                back = newNode;
        }
        else
        {
            newNode->next = front;
            front = newNode;
        }
        size++;
    }

    void Push_back(int val)
    {
        Node* newNode = new Node;
        newNode->value = val;
        if (back == nullptr)
        {
            back = newNode;
            if (front == nullptr)
                front = newNode;            
        }
        else
        {
            newNode->next = back;
            back = newNode;
        }
        size++;
    }

    void Pop_front()
    {
        if (front != nullptr)
        {
            Node* temp = front;
            cout << front->value << "\n";
            front = front->next;            
            delete(temp);      
        }
        else
            cout << -1 << "\n";

        if (size > 0) size--;

        if (size == 1) front = back;
    }

    void Pop_back()
    {
        if (back != nullptr)
        {
            Node* temp = back;
            cout << back->value << "\n";
            back = back->next;
            delete(temp);
        }
        else
            cout << -1 << "\n";

        if (size > 0) size--;

        if (size == 1) back = front;
    }
    void Size()
    {
        cout << size << "\n";
    }

    void Empty()
    {
        if (size != 0) cout << 0 << "\n";
        else cout << 1 << "\n";
    }

    void Front()
    {
        if (size != 0 && front != nullptr) cout << front->value << "\n";
        else cout << -1 << "\n";
    }

    void Back()
    {
        if (size != 0 && back != nullptr) cout << back->value << "\n";
        else cout << -1 << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0, val = 0;
    cin >> N;
    string oper = "";
    MyDeque myDeque;
    for (int i = 0; i < N; ++i)
    {
        cin >> oper;        
        if (oper == "push_front")
        {
            cin >> val;
            myDeque.Push_front(val);
        }
        if (oper == "push_back")
        {
            cin >> val;
            myDeque.Push_back(val);
        }
        if (oper == "pop_front") myDeque.Pop_front();
        if (oper == "pop_back") myDeque.Pop_back();
        if (oper == "size") myDeque.Size();
        if (oper == "empty") myDeque.Empty();
        if (oper == "front") myDeque.Front();
        if (oper == "back") myDeque.Back();
    }
}