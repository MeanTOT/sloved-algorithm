#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;
vector<tuple<int, int, string>> people;

bool Comp(tuple<int, int, string> a, tuple<int, int, string> b)
{
    if (get<0>(a) == get<0>(b))
    {
        return get<1>(a) < get<1>(b);
    }

    return get<0>(a) < get<0>(b);
}

int main()
{
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int age = 0;
        string name = "";
        cin >> age >> name;
        people.push_back({ age, i + 1, name });
    }

    sort(people.begin(), people.end(), Comp);

    for (int i = 0; i < N; ++i)
    {
        cout << get<0>(people[i]) << " " << get<2>(people[i]) << "\n";
    }
}