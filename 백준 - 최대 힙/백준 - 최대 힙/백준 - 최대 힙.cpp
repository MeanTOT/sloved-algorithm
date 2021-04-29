#include <iostream>
#include <vector>
using namespace std;
vector<int> heap;
void push(int value)
{
    heap.push_back(value);
    int index = heap.size() - 1;
    while (index > 0 && heap[(index - 1) / 2] < heap[index])
    {
        int temp = heap[(index - 1) / 2];
        heap[(index - 1) / 2] = heap[index];
        heap[index] = temp;
        index = (index - 1) / 2;
    }
}
void pop()
{
    if (heap.size() == 0)
    {
        printf("0\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap.back();
    heap.pop_back();
    int index = 0;
    while (true)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left >= heap.size()) break;
        int next = index;
        if (heap[next] < heap[left]) next = left;
        if (right < heap.size() && heap[next] < heap[right]) next = right;
        if (next == index) break;
        int temp = heap[index];
        heap[index] = heap[next];
        heap[next] = temp;
        index = next;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x = 0;
        cin >> x;

        if (x > 0) push(x);
        else pop();
    }
}