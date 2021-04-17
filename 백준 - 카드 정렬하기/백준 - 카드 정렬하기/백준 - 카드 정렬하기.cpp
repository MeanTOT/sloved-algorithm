#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N = 0;
priority_queue<int, vector<int>, greater<int>> bunchOfCards;
int solution()
{
    if (bunchOfCards.size() == 1) return 0;

    int result = 0;
    while (bunchOfCards.size() != 1)
    {
        int cards_1 = bunchOfCards.top(); bunchOfCards.pop();
        int cards_2 = bunchOfCards.top(); bunchOfCards.pop();
        result += cards_1 + cards_2;
        bunchOfCards.push(cards_1 + cards_2);
    }

    return result;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int amount = 0;
        cin >> amount;
        bunchOfCards.push(amount);
    }
    printf("%lld", solution());
}