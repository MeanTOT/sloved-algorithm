#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int T = 0;
    std::cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int A = 0, B = 0;
        std::cin >> A >> B;
        std::cout << A + B << '\n';
    }
}