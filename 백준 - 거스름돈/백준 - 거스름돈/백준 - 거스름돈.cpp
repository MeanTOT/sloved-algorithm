#include <iostream>
using namespace std;
int payedMoney = 0;
int solution()
{
    int result = 0;
    int change = 1000 - payedMoney;
    int changes[6] = { 500, 100, 50, 10, 5, 1 };
    int index = 0;
    while (change > 0)
    {
        if (change - changes[index] < 0)
            index++;
        else
        {
            change -= changes[index];
            result++;
        }
    }
    return result;
}
int main()
{
    cin >> payedMoney;
    cout << solution();
}