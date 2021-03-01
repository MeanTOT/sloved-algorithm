#include <iostream>
#include <string>

using namespace std;

bool IsExistOverlap(string param);

int main()
{
	string arg = "zxcmaksjdoqiwue";

	cout << IsExistOverlap(arg); 

	return 0;
}

bool IsExistOverlap(string param)
{
	for (int i = 0; i < param.length(); i++)
	{
		for (int j = i + 1; j < param.length(); j++)
		{
			if (param[i] == param[j])
			{
				return true;
			}
		}
	}

	return false;
}