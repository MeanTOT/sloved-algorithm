#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int Find110(string s, stack<char>& _stack)
{
	int result = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		char z = s[i];

		if (_stack.size() >= 2)
		{
			char y = _stack.top(); _stack.pop();
			char x = _stack.top(); _stack.pop();

			if (x == '1' && y == '1' && z == '0')
			{
				result++;
				continue;
			}
			else
			{
				_stack.push(x);
				_stack.push(y);
				_stack.push(z);
			}
		}
		else
		{
			_stack.push(z);
		}
	}
	return result;
}

void SingleSolution(string& s)
{
	stack<char> _stack;
	int count110 = Find110(s, _stack);
	int index = _stack.size();
	bool isZero = false;
	string temp = "";
	while (!_stack.empty())
	{
		if (!isZero && _stack.top() == '1') index--;
		if (!isZero && _stack.top() == '0') isZero = true;
		temp.insert(0, to_string(_stack.top() - 48)); _stack.pop();
	}

	while (count110--)
	{
		temp.insert(index, "110");
		index += 3;
	}

	s = temp;
}

vector<string> solution(vector<string> s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		SingleSolution(s[i]);
	}
	return s;
}

int main()
{
	vector<string> result = solution({ "1110","100111100","0111111010" });
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
}
