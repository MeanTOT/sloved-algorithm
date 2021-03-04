#include <iostream>

void Init(int maxSize, int matrix[][5]);
void Rotate(int minIndex, int maxIndex, int matrix[][5]);

int main()
{
	const int size = 5;
	int matrix[5][5];	
	Init(size, matrix);

	Rotate(0, 4, matrix);

	return 0;
}

void Init(int maxSize, int matrix[][5])
{
	int value = 0;

	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			matrix[i][j] = value;
			value++;
		}
	}
}

void Rotate(int minIndex, int maxIndex, int matrix[][5])
{
	int currentSize = maxIndex + 1;

	while (currentSize != 0)
	{
		int temp = maxIndex;
		int temp2 = minIndex;

		for (int i = minIndex; i < maxIndex; i++)
		{
			int current_i = minIndex;
			int current_j = i;

			int currentValue = matrix[minIndex][i]; 
			int targetValue = matrix[current_j][maxIndex];
			matrix[current_j][maxIndex] = currentValue;
			current_i = current_j;
			current_j = maxIndex;

			currentValue = targetValue;
			targetValue = matrix[maxIndex][temp];
			matrix[maxIndex][temp] = currentValue;
			current_j = temp;
			current_i = maxIndex;

			currentValue = targetValue;
			targetValue = matrix[current_j][minIndex];
			matrix[current_j][minIndex] = currentValue;
			current_i = current_j;
			current_j = minIndex;

			currentValue = targetValue;
			targetValue = matrix[minIndex][temp2];
			matrix[minIndex][temp2] = currentValue;
			current_i = minIndex;
			current_j = temp2;

			temp--;
			temp2++;
		}

		maxIndex--;
		minIndex++;
		currentSize /= 2;
	}
}
