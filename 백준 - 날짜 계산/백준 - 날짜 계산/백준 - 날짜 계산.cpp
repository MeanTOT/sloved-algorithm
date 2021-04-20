#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int GCD(int A, int B)
{
	if (B == 0) return A;
	return GCD(B, A % B);
}
int main()
{
	int N = 0;
	cin >> N;
	vector<int> aliquots(N);	
	for (int i = 0; i < N; i++) cin >> aliquots[i];	
	sort(aliquots.begin(), aliquots.end());

	int num = aliquots[aliquots.size() -1];
	cout << aliquots[aliquots.size() - 1] * aliquots[0];
}