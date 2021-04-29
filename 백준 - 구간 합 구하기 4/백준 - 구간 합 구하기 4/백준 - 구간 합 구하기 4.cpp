#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    int N, M = 0;
	vector<int> arr;
    cin >> N >> M;
	int value = 0;
	while (N--)
	{
		int x = 0;
		cin >> x;
		value += x;
		arr.push_back(value);
	}
	while (M--)
	{
		int i, j, result = 0;
		cin >> i >> j;
		if (i == 1) printf("%d\n", arr[j - 1]);
		else printf("%d\n", arr[j - 1] - arr[i - 2]);
	}
}