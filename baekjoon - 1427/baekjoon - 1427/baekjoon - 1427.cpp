#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums;
int main()
{
    char num = 0;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] - '0';
    }
}