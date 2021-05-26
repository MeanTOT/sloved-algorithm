#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N = 0;
    cin >> N;
    queue<int> card;

    for (int i = 1; i <= N; ++i)
    {
        card.push(i);
    }

    while (card.size() != 1)
    {
        card.pop();
        int temp = card.front();
        card.pop();
        card.push(temp);
    }

    cout << card.front();
}