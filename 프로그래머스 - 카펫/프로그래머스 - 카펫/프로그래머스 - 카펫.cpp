#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;

    int widthBlocks = brown - 2;
    int heightBlocks = 2;

    while (widthBlocks >= heightBlocks)
    {
        int width = widthBlocks / 2;
        int height = (heightBlocks / 2) + 2;

        if ((width * height) - brown == yellow)
        {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }

        widthBlocks -= 2;
        heightBlocks += 2;
    }

    return answer;
}

int main()
{
    solution(24, 24);

    return 0;
}