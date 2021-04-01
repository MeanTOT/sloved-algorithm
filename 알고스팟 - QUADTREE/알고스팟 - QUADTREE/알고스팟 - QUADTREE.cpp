#include <iostream>
#include <string>

using namespace std;

string QuadSearch(string quadtree, int& index)
{
    string quadrant[4];      
    int currentQuadrant = 0;
    int leftQaudrant = 4;
    string result = "";
    while (leftQaudrant > 0 && index < quadtree.size())
    {
        result = "";

        if (quadtree[index] == 'x')
        {
            index += 1;
            result += QuadSearch(quadtree, index);
        }
        else
        {
            result += quadtree[index];
            index += 1;
        }

        quadrant[currentQuadrant] = result;
        leftQaudrant--;        
        currentQuadrant++;
    }

    return "x" + quadrant[2] + quadrant[3] + quadrant[0] + quadrant[1];
}

string solution(string quadtree)
{
    if (quadtree.length() == 1)
        return quadtree;

    int startIndex = 1;
    return QuadSearch(quadtree, startIndex);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string quadtree = "";
        cin >> quadtree;
        cout << solution(quadtree) << endl;
    }
}