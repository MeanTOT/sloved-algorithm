#include <iostream>
#include <string>

using namespace std;

bool IsExistOverlap(string param);
bool IsExistOverlap_Answer(string param);

int main()
{
	string arg = "bcbmaksjdoqiwue";

	cout << IsExistOverlap_Answer(arg);

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

bool IsExistOverlap_Answer(string param)
{
	int checker = 0;
	for (int i = 0; i < param.length(); i++)
	{
		int val = param.at(i) - 'a';
		if ((checker & (1 << val)) > 0)
			return false;

		checker |= (1 << val);
	}

	return true;
}