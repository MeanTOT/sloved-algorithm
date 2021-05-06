#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int C = 0;
    cin >> C;
    while (C--)
    {
        int N = 0;
        int amount = 0;
        int average = 0;
        vector<int> scores;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            int score = 0;
            cin >> score;
            scores.push_back(score);
            amount += score;
        }
        average = amount / (float)N;
        int overAverages = 0;

        for (int i = 0; i < scores.size(); ++i)
        {
            if (average < scores[i])
                overAverages++;
        }

        printf("%0.3f%%\n", overAverages / (float)N * 100);
    }
}