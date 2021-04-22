#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int K = 0;
	int answer = 0;
	stack<int> numbers;
    cin >> K;
	while (K--)
	{
		int number = 0;
		cin >> number;
		if (number == 0)
		{
			answer -= numbers.top();
			numbers.pop();
		}
		else
		{
			answer += number;
			numbers.push(number);
		}
	}
	cout << answer;
}