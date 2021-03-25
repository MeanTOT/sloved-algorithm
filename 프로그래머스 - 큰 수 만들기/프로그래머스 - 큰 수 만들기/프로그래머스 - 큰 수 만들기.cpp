#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
    while (k-- > 0)
    {        
        for (int i = 0; i < number.size() - 1; i++)
        {
            if (number[i] < number[i + 1])
            {
                number.erase(i, 1);    
                break;
            }

            if (i + 1 == number.size() - 1 && number[i + 1] < number[i])
            {
                number.erase(i + 1, 1);
                break;
            }
        }        
    }

    return number;
}

int main()
{
    solution("1941", 2);

    return 0;
}