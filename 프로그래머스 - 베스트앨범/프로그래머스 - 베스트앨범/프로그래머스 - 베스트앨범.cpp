#include <iostream>
#include <vector>
#include <map>  
#include <algorithm>

using namespace std;

struct SongData
{    
    int index;
    int playCount;
};

bool cmp(SongData data1, SongData data2)
{
    if (data1.playCount == data2.playCount)
        return data1.index < data2.index;
    return data1.playCount > data2.playCount;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    map<string, vector<SongData>> AllSongs;
    map<int, vector<SongData>, greater<int>> AllSongsOrderd;
    for (int i = 0; i < genres.size(); i++)
    {
        SongData data{ i, plays[i] };
        AllSongs[genres[i]].push_back(data);
    }

    for (auto genre : AllSongs)
    {
        int PlayAmount = 0;
        for (int i = 0; i < genre.second.size(); i++)
        {
            PlayAmount += genre.second[i].playCount;
        }
        AllSongsOrderd[PlayAmount] = genre.second;
        sort(AllSongsOrderd[PlayAmount].begin(), AllSongsOrderd[PlayAmount].end(), cmp);
    }

    for (auto genre : AllSongsOrderd)
    {
        if (genre.second.size() > 1)
        {
            answer.push_back(genre.second[0].index);
            answer.push_back(genre.second[1].index);
        }   
        else if (genre.second.size() == 1)
        {
            answer.push_back(genre.second[0].index);
        }
    }

    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    solution(genres, plays);

    return 0;
}