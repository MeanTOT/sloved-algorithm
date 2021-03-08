#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input = 1775;
	int count = 0;
	int max = 0;
	bool hasOne = true;

	while (input / 2 != 1)
	{
		int remainder = input % 2;		

		if (remainder == 1)
		{
			count++;
		}
		else
		{
			if (hasOne)
			{
				count++;
				hasOne = false;
			}
			else
			{
				if (count > max)
				{
					max = count;
				}
				count = 0;
			}
		}

		input /= 2;
	}

	cout << max << endl;

	return 0;
}