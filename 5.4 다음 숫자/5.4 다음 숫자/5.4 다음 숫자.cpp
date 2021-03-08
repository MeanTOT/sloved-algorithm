#include <iostream>
#include <bitset>

using namespace std;

// 양의 정수가 하나 주어졌다. 이 숫자를 2진수로 표기했을때 1비트의 개수가 같은 숫자중에서 다음으로 큰수와 다음으로 작은수를 구하라.

int GetNextNumber(int value)
{
	int c = value;
	int c0 = 0;
	int c1 = 0;

	if (c % 2 == 0)
	{
		while (c % 2 == 0)
		{
			c0++;
			c >>= 1;
		}

		while (c % 2 == 1)
		{
			c1++;
			c >>= 1;
		}
	}
	else
	{
		while (c % 2 == 1)
		{
			c1++;
			c >>= 1;
		}
	}	

	int p = c1 + c0;

	value = value | (1 << p);
	value = value & ~((1 << p) - 1);
	value = value | ((1 << (c1 - 1)) - 1);

	return value;
}

int GetPrevNumber(int value)
{
	int c = value;
	int c0 = 0;
	int c1 = 0;

	if (c % 2 == 0)
	{
		while (c % 2 == 0)
		{
			c0++;
			c >>= 1;
		}
	}
	else
	{
		while (c % 2 == 1)
		{
			c1++;
			c >>= 1;
		}

		while (c % 2 == 0)
		{
			c0++;
			c >>= 1;
		}
	}	

	int p = c1 + c0;
	value = value & ~((1 << p + 1) - 1);	
	value = value | (((1 << c1 + 1) - 1) << (c1 + 1));

	return value;
}

int main()
{
	int input = 13948; // 11011001111100
	//next : 11011010001111 : 13967
	//prev : 11011001111010 : 13946
	cout << GetNextNumber(input) << endl;
	cout << GetPrevNumber(input) << endl;
	return 0;
}