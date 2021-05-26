#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N = 0;
vector<int> numbers;
set<int> Answer;
int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num = 0;
		cin >> num;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());

	int gcd = numbers[1] - numbers[0];
	for (int i = 2; i < N; ++i)
	{
		gcd = GCD(gcd, numbers[i] - numbers[i - 1]);
	}

	for (int i = 2; i * i <= gcd; ++i)
	{
		if (gcd % i == 0)
		{
			Answer.insert(i);
			Answer.insert(gcd / i);
		}
	}
	Answer.insert(gcd);

	for (auto iter = Answer.begin(); iter != Answer.end(); ++iter)
	{
		cout << *iter << " ";
	}
}