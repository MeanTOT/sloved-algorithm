#include <iostream>
#include <vector>
using namespace std;
int A = 0;
int MaxLength = 0;
vector<int> numbers;
//void dp(int previous, int index, int length)
//{
//	if (index == numbers.size())
//	{
//		MaxLength = max(MaxLength, length);
//		return;
//	}
//	
//	if (numbers[index] > previous)
//	{
//		dp(numbers[index], index + 1, length + 1);
//	}
//	else
//	{
//		dp(numbers[index], index + 1, 1);
//	}
//
//	dp(previous, index + 1, length);
//}
void Search(int previous, int index, int length)
{
	if (index == numbers.size())
	{
		MaxLength = max(MaxLength, length);
		return;
	}

	if (numbers[index] > previous)
	{
		Search(numbers[index], index + 1, length + 1);
	}
	else
	{
		Search(previous, index + 1, length);
	}
}
int solution()
{
	//dp(0, 0, 0);
	for (int i = 0; i < numbers.size(); i++)
	{
		Search(0, i, 1);
	}
	return MaxLength;
}
int main()
{
	cin >> A;
	numbers.resize(A);
	for (int i = 0; i < A; i++)
	{
		cin >> numbers[i];
	}
	cout << solution();
}
