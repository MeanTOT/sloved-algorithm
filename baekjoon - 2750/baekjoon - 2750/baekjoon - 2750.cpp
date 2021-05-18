#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<int> numbers;
void Sort()
{

    for (int j = 0; j < numbers.size(); ++j)
    {
        for (int i = 0; i < numbers.size() - 1; ++i)
        {
            if (numbers[i] > numbers[i + 1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
            }
        }
    }    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    while (N--)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    Sort();

    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << "\n";
    }
}