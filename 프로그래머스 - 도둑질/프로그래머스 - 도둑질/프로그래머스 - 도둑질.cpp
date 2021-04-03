#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int cache[2][1000000];
int N = 0;
int dp(vector<int>& money, int index, bool firstHouseRobbed)
{
    if (index >= N)
        return 0;
    else if (index == N - 1 && firstHouseRobbed)
        return 0;
    else if (index == N - 1 && !firstHouseRobbed)
        return money[N - 1];

    int& ref = cache[firstHouseRobbed][index];
    if (ref != -1)
        return ref;

    int result1 = 0;
    int result2 = 0;
    result1 = money[index] + dp(money, index + 2, firstHouseRobbed);
    result2 = dp(money, index + 1, firstHouseRobbed);

    ref = max(result1, result2);
    return ref;
}

int solution(vector<int> money) 
{
    N = (int)money.size();
    memset(cache, -1, sizeof(cache));
    int result1 = dp(money, 0, true);
    int result2 = dp(money, 1, false);
    int answer = max(result1, result2);
    return answer;
}

int main()
{
    vector<int> money = { 1, 1, 4, 1, 4 };
    solution(money);
}
