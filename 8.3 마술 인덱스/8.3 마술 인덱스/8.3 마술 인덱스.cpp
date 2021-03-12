#include <iostream>

using namespace std;

int FindMagicIndex(int arr[], int searchIndex, int size)
{
    if (arr[searchIndex] < 0 || arr[searchIndex] < searchIndex)
    {
        if (size - searchIndex == 1)
            return -50000;
        else
            return FindMagicIndex(arr, (searchIndex + size) / 2, size);
    }
    else if (arr[searchIndex] > searchIndex)
    {
        return FindMagicIndex(arr, (searchIndex) / 2, size);
    }
    else if (arr[searchIndex] == searchIndex)
    {
        return searchIndex;
    }        
}

int main()
{
    int A[6] = { -5, -5, -5, 3, 5, 6};

    cout << FindMagicIndex(A, 6 / 2, 6);

    return 0;
}
