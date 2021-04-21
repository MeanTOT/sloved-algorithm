#include <bitset>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int Set = 0;
void add(int x)
{
    Set |= (1 << x);
}
void remove(int x)
{
    Set &= ~(1 << x);
}
bool check(int x)
{
    return Set & (1 << x);
}
void toggle(int x)
{
    Set ^= (1 << x);
}
void all()
{
    Set = ((1 << 21) - 1);
}
void empty()
{
    Set = 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int M = 0;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string oper = "";
        int x = 0;
        cin >> oper;
        if (oper != "all" && oper != "empty") cin >> x;
        if (oper == "add") add(x);
        else if (oper == "check") printf("%d\n", check(x));
        else if (oper == "remove") remove(x);
        else if (oper == "toggle") toggle(x);
        else if (oper == "all") all();
        else if (oper == "empty") empty();
    }
}