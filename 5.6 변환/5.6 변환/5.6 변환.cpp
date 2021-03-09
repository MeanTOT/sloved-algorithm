#include <iostream>

int Transform(int param1, int param2)
{
    int result = 0;
    
    for (int c = param1 ^ param2; c != 0; c >>= 1)
    {
        result += c & 1;
    }

    return result;
}   

int main()
{
    std::cout << Transform(29, 15);

    return 0;
}
