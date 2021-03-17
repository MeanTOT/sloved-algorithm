#include <iostream>

void SelectionSort(int data[], int size);

int main()
{
	int data[5] = { 4, 1, 5,3,7 };

	SelectionSort(data, sizeof(data) / sizeof(int));

	return 0;
}

void SelectionSort(int data[], int size)
{
	int minIndex;

	for (int i = 0; i < size; i++)
	{
		minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}
		
		int temp = data[i];
		data[i] = data[minIndex];
		data[minIndex] = temp;
	}
}
