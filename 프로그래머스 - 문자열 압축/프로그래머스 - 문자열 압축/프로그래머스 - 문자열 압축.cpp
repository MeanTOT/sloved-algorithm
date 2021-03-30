#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1001;
    int sliceCount = 1;
    int sameStringCount = 1;

    if (s.length() <= 2)
        return s.length();

    while (sliceCount <= s.length() / 2 + s.length() % 2)
    {
        string slicedString = s.substr(0, sliceCount);
        string pressuredString = "";
        for (int i = sliceCount; i <= s.length(); i += sliceCount)
        {
            if (slicedString == s.substr(i, sliceCount))
            {
                ++sameStringCount;
            }
            else
            {
                if (sameStringCount > 1)
                {
                    pressuredString += to_string(sameStringCount) + slicedString;
                }
                else
                {
                    pressuredString += slicedString;
                }

                slicedString = s.substr(i, sliceCount);
                sameStringCount = 1;
            }
        }

        if (sameStringCount > 1)
        {
            pressuredString += to_string(sameStringCount) + slicedString;
        }
        else
        {
            pressuredString += slicedString;
        }

        answer = min(answer, (int)pressuredString.length());

        sliceCount++;
    }

    return answer;
}

int main()
{
    solution("xababcdcdababcdcd");

    return 0;
}