#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool MinusOne(string param1, string param2);

int main()
{
	string arg1 = "pale";
	string arg2 = "pales";

	cout << MinusOne(arg1, arg2);

	return 0;
}

bool MinusOne(string param1, string param2)
{
	if (abs((int)param1.length() - (int)param2.length()) >= 2)
	{
		return false;
	}

	int fixCount = 0;	
	if (abs((int)param1.length() - (int)param2.length()) == 1)
	{
		for (int i = 0; i < param1.length(); i++)
		{
			if (param1[i] != param2[i])
			{
				if (param1.length() > param2.length())
				{
					param1.erase(i, 1);

					if (strcmp(param2.c_str(), param1.c_str()) == 0)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					param2.erase(i, 1);

					if (strcmp(param2.c_str(), param1.c_str()) == 0)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}			
		}
	}
	else // 두 문자열의 길이가 같다.
	{
		for (int i = 0; i < param1.length(); i++)
		{
			if (param1[i] != param2[i])
			{
				fixCount++;
			}
		}
	}

	if (fixCount > 1)
		return false;
	else
		return true;
}


