#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int maxLenth = 0;
    for (size_t i = triangle.size() - 1; i > 0; --i)
    {
        for (size_t j = 0; j < triangle[i].size() - 1; ++j)
        {
            maxLenth = max(triangle[i][j], triangle[i][j + 1]);
            triangle[i - 1][j] += maxLenth;
        }
    }
    return triangle[0][0];
}

int main()
{
    vector<vector<int>> triangle = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5} };

    solution(triangle);

    return 0;
}