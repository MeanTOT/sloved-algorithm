#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

string Number = "";

int cache[10002];
int const INF = 987654321;
bool IsDifficulty_1(string number)
{
	char temp = number[0];
	for (int i = 1; i < number.size(); i++)
	{
		if (temp != number[i])
			return false;
	}

	return true;
}

bool IsDifficulty_2(string number)
{
	char temp1 = number[0];
	char temp2 = number[1];
	int interval = number[0] - number[1];
	if (interval == 1 || interval == -1)
	{
		for (int i = 1; i < number.size() - 1; i++)
		{
			if (number[i] - number[i + 1] != interval)
				return false;
		}
	}
	else
		return false;


	return true;
}

bool IsDifficulty_4(string number)
{
	char temp1 = number[0];
	char temp2 = number[1];
	for (int i = 2; i < number.size(); i++)
	{
		if ((i % 2 == 0 && number[i] == temp1) || (i % 2 == 1 && number[i] == temp2))
		{

		}
		else
			return false;
	}

	return true;
}

bool IsDifficulty_5(string number)
{
	char temp1 = number[0];
	char temp2 = number[1];
	int interval = abs(number[0] - number[1]);
	for (int i = 1; i < number.size() - 1; i++)
	{
		if (abs(number[i] - number[i + 1]) != interval)
			return false;
	}

	return true;
}

int GetDifficulty(string number)
{
	int result = 10;

	if (IsDifficulty_1(number))
		result = 1;
	else if (IsDifficulty_2(number))
		result = 2;
	else if (IsDifficulty_4(number))
		result = 4;
	else if (IsDifficulty_5(number))
		result = 5;		

	return result;
}

int dp(int start)
{
	if (start == Number.length())
		return 0;
	
	int& result = cache[start];
	if (result != -1)
		return result;

	result = INF;
	for (int i = 3; i <= 5; ++i)
	{
		if (start + i <= Number.length())
		{
			result = min(result, dp(start + i) + GetDifficulty(Number.substr(start, i)));
		}		
	}	

	return result;
}

int solution(string number)
{
	Number = number;
	memset(cache, -1, sizeof(cache));

	int result = dp(0);

	return result;
}

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		string number;
		cin >> number;
		cout << solution(number) << endl;
	}
}