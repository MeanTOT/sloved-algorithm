#include <iostream>

void MergeSort(int data[], int helper[], int low, int high);
void Merge(int data[], int helper[], int low, int middle, int high);

int main()
{
    int data[8] = { 1, 7, 3, 4, 8, 9, 2, 10 };
    int helper[8];
    MergeSort(data, helper, 0, sizeof(data) / sizeof(int) - 1);

    return 0;
}

void MergeSort(int data[], int helper[], int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        MergeSort(data, helper, low, middle);
        MergeSort(data, helper, middle + 1, high);
        Merge(data, helper, low, middle, high);
    }    
}

void Merge(int data[], int helper[], int low, int middle, int high)
{
    for (int i = low; i <= high; i++)
    {
        helper[i] = data[i];
    }

    int leftIndex = low;
    int rightIndex = middle + 1;
    int current = low;

    while (leftIndex <= middle && rightIndex <= high)
    {
        if (helper[leftIndex] <= helper[rightIndex])
        {
            data[current] = helper[leftIndex];
            leftIndex++;
        }
        else
        {
            data[current] = helper[rightIndex];
            rightIndex++;
        }
        current++;
    }

    int remaining = middle - leftIndex;
    for (int i = 0; i <= remaining; i++)
    {
        data[current + i] = helper[leftIndex + i];
    }
}
