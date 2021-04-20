#include <iostream>
using namespace std;
int main()
{
    int all = 0;
    int sum = 0;
    cin >> all;
    for (int i = 0; i < 9; i++)
    {
        int price = 0;
        cin >> price;
        sum += price;
    }
    cout << all - sum;
}