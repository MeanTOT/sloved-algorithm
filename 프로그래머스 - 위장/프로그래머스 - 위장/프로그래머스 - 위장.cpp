#include <iostream>
#include <vector>
#include <map>  

using namespace std;

int solution(vector<vector<string>> clothes)
{
    map<string, vector<string>> closet;
    for (size_t i = 0; i < clothes.size(); i++)
    {
        closet[clothes[i][1]].push_back(clothes[i][0]);        
    }
    
    int result = 1;
    for (auto iter = closet.begin(); iter != closet.end(); ++iter)
    {
        result *= iter->second.size() + 1;
    }
    return result - 1;
}

int main()
{
    vector<vector<string>> testCase = {
        {"yellow_hat", "headgear"},
        {"yellow_hat", "headgear"},
        {"green_turban", "headgear"},
        {"crow_mask", "face"},
        {"blue_sunglasses", "face"},
        {"smoky_makeup", "face"},
        {"smoky_makeup", "face"},
        {"blue_sunglasses", "eyewear"},
        {"blue_sunglasses", "eyewear"},
        {"blue_sunglasses", "top"}, 
        {"blue_sunglasses", "top"},
        {"blue_sunglasses", "top"}, };
    cout << solution(testCase);

    return 0;
}
