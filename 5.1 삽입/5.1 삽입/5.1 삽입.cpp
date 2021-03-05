#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

int Insert()
{
    int N = 1023;
    int M = 32;

    int i = 2;
    int j = 6;    

    cout << "N : " << bitset<32>(N) << endl;
    cout << "M : " << bitset<32>(M) << endl;

    return (M << i) | (N & ~((int)pow(2, 5) - 1 << i));
}

int main()
{
    cout << "R : " << bitset<32>(Insert());

    return 0;
}