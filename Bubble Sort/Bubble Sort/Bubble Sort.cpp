#include <iostream>

void BubbleSort(int data[], int size);

int main()
{
    int data[10] = { 6, 2, 3, 8, 7, 9, 11, 15, 1, 21 };

    BubbleSort(data, sizeof(data) / sizeof(int));

    return 0;
}

void BubbleSort(int data[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;                
            }
        }        
    }
}
