#include <iostream>
using namespace std;
bool NotSelfNumber[10001];
void d(int n)
{
	int sum = 0;
	int result = n;
	while (n / 10 != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	result += sum + n;	
	if (result <= 10000)
	{
		NotSelfNumber[result] = true;
		d(result);
	}
	return;
}

int main()
{
	for (int i = 1; i <= 10000; ++i)
	{
		if (!NotSelfNumber[i])
		{
			d(i);
			printf("%d\n", i);
		}
	}	
}