#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string A = "", B = "";
	vector<int> result;
	cin >> A >> B;

	int AI = A.length() - 1;
	int BI = B.length() - 1;
	int carry = 0;
	while (true)
	{
		int a = (int)(A[AI] - '0');
		int b = (int)(B[BI] - '0');

		if (a + b + carry >= 10)
		{
			result.push_back((a + b + carry) % 10);		
			if (carry >= 1) carry--;
			carry++;
		}
		else
		{
			result.push_back(a + b + carry);
			if (carry >= 1) carry--;
		}		

		AI--;
		BI--;

		if (AI < 0 || BI < 0) break;
	}

	if (AI > BI)
	{
		while (true)
		{
			int a = (int)(A[AI] - '0');

			if (a + carry >= 10)
			{
				result.push_back((a + carry) % 10);
				if (carry >= 1) carry--;
				carry++;
			}				
			else
			{
				result.push_back((a + carry));
				if (carry >= 1) carry--;
			}

			AI--;
			if (AI < 0) break;
		}
	}	
	if (AI < BI)
	{
		while (true)
		{
			int b = (int)(B[BI] - '0');

			if (b + carry >= 10)
			{
				result.push_back((b + carry) % 10);
				if (carry >= 1) carry--;
				carry++;
			}
			else
			{
				result.push_back((b + carry));
				if (carry >= 1) carry--;
			}

			BI--;
			if (BI < 0) break;
		}
	}

	if (carry >= 1) result.push_back(carry);

	for (int i = result.size() - 1; i >= 0; --i)
	{
		cout << result[i];
	}
}