#include <iostream>
#include <bitset>

using namespace std;

int Swap(int param)
{
	int result = 0;
	int count = 0;

	while (param != 0)
	{
		int evenNumber = param % 2;
		int oddNumber = (param / 2) % 2;

		param >>= 2;

		result |= oddNumber << count;
		result |= evenNumber << count + 1;

		count += 2;
	}	

	return result;
}

int main()
{
	int arg = 554; // 1000101010
	               // 0100010101
	cout << bitset<32>(Swap(arg)) << endl;

	return 0;
}