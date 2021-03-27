#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) 
{
    string answer = "";
    while (true)
    {
        int remainder = n % 3;
        int quotient = n / 3;

        if (remainder == 0)
        {
            remainder = 4;
            quotient--;            

            if (quotient == 3)
            {
                quotient = 4;
                answer += to_string(remainder);
                answer += to_string(quotient);
                break;
            }
        }        

        answer += to_string(remainder);        
        n = quotient;

        if (n < 3)
        {
            if (n != 0)
                answer += to_string(n);
            
            break;
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    for (int i = 1; i < 25; i++)
    {
        std::cout << i << ": " <<  solution(i) << endl;;

    }

    return 0;
}