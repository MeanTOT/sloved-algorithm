#include <iostream>
using namespace std;
double PI = 3.141592653589793;
int main()
{
    double R = 0;
    cin >> R;
    cout << fixed;
    cout.precision(6);
    cout << R * R * PI << "\n";
    cout << R * R * 2.0 << "\n";
}