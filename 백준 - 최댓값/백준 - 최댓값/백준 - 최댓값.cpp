#include <iostream>
using namespace std;
int main()
{
	int pos = 0, max = 0, maxI = 0, num = 0;
	for (int i = 0; i < 9; i++)
	{		
		cin >> num;
		++pos;
		if (max < num)
		{
			max = num;			
			maxI = pos;
		}
	}
	printf("%d\n%d", max, maxI);
}