#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N = 0;
	string OX = "";
	cin >> N;
	while (N--)
	{
		cin >> OX;
		int score = 0;
		int answer = 0;
		for (int i = 0; i < OX.length(); ++i)
		{
			if (OX[i] == 'O') answer += ++score;
			else score = 0;
		}
		cout << answer << "\n";
	}
}