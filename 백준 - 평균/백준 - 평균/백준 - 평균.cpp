#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N = 0;
    float num = 0.0f;
    vector<float> scores;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        scores.push_back(num);
    }

    float _max = scores[0];
    for (int i = 1; i < scores.size(); ++i)
    {
        if (_max < scores[i])
            _max = scores[i];
    }
    float amount = 0;
    for (int i = 0; i < scores.size(); ++i)
    {
        amount += scores[i] / _max * 100;
    }
    cout << amount / (float)scores.size();
}