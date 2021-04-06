#include <iostream>
#include <string>   

using namespace std;

int solution(int N)
{
    int answer = 0;

    while (N % 5 != 0)
    {
        N -= 3;
        answer++;
        if (N <= 0)
            break;
    }
    if (N < 0)
        return -1;
    if (N % 5 == 0)
        answer += N / 5;

    return answer;
}

int main()
{
    int N = 0;
    cin >> N;
    cout << solution(N);
}