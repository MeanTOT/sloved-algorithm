#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<int> numbers;
vector<int> sorted;

void Merge(int start, int mid, int end)
{
    for (int i = start; i <= end; ++i)
    {
        sorted[i] = numbers[i];
    }

    int sortedLeft = start;
    int sortedRight = mid + 1;
    int current = start;

    while (sortedLeft <= mid && sortedRight <= end)
    {
        if (sorted[sortedLeft] <= sorted[sortedRight])
        {
            numbers[current] = sorted[sortedLeft];
            sortedLeft++;
        }
        else
        {
            numbers[current] = sorted[sortedRight];
            sortedRight++;
        }
        current++;
    }

    int remaining = mid - sortedLeft;
    for (int i = 0; i <= remaining; ++i)
    {
        numbers[current + i] = sorted[sortedLeft + i];
    }
}

void MergeSort(int start, int end)
{
    if (end == start) return;
    int mid = (start + end) / 2;
    MergeSort(start, mid);    
    MergeSort(mid + 1, end);
    Merge(start, mid, end);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    sorted.resize(N);
    for (int i = 0; i < N; ++i)
    {
        int num = 0;
        cin >> num;
        numbers.push_back(num);
    }

    MergeSort(0, N - 1);
    for (int i = 0; i < N; ++i)
    {
        cout << numbers[i] << "\n";
    }
}