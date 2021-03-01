#include <iostream>
#include <string>

using namespace std;

bool IsPermutation(string param1, string param2);

int main()
{
	string arg1 = "asdawda";
	string arg2 = "gqgqwg";

	cout << IsPermutation(arg1, arg2);

	return 0;
}

bool IsPermutation(string param1, string param2)
{
	for (size_t i = 0; i < param1.length(); i++)
	{
		size_t foundIndex = param2.find(param1[i]);

		if (foundIndex != string::npos)
		{
			param2.erase(foundIndex, 1);
		}
	}

	if (param2.length() == 0)
		return true;

	return false;
}
