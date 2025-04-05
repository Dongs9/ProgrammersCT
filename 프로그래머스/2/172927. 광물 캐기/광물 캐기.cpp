#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dia[] = { 1, 5, 25 };
int iron[] = { 1, 1, 5 };
int stone[] = { 1 , 1, 1 };

struct Fatigue
{
public:
    vector<string> minerals;
    int fatigue = 0;
};
vector<Fatigue> vecSectionFatigue;

int Score(int pick, string mineral)
{
    if ("stone" == mineral)
        return stone[pick];
    else if ("iron" == mineral)
        return iron[pick];
    else
        return dia[pick];
}

int solution(vector<int> picks, vector<string> minerals)
{
    if (picks.empty() || minerals.empty())
        return 0;

    vector<int> pick_list;
    for (int i = 0; i < picks.size(); ++i)
    {
        for (int j = 0; j < picks[i]; ++j)
            pick_list.push_back(i);
    }

    vector<Fatigue> vecFatigue;
    Fatigue stFatigue;
    for (int i = 0; i < minerals.size(); ++i)
    {
        if (i % 5 == 0 && i > 0)
        {
            vecFatigue.push_back(stFatigue);

            stFatigue.minerals.clear();
            stFatigue.fatigue = 0;
        }

        stFatigue.minerals.push_back(minerals[i]);
        stFatigue.fatigue += Score(2, minerals[i]);
    }

        if (minerals.size() <= pick_list.size() * 5)
        vecFatigue.push_back(stFatigue);

     std::sort(vecFatigue.begin(), vecFatigue.end(), [](Fatigue a, Fatigue b) 
     {
         if (a.fatigue == b.fatigue)
             return a.minerals.size() < b.minerals.size();

         return a.fatigue > b.fatigue; 
     });
    
    int answer = 0;
    for (int i = 0; i < vecFatigue.size(); ++i)
    {
        for (int j = 0; j < vecFatigue[i].minerals.size(); ++j)
            answer += Score(pick_list[i], vecFatigue[i].minerals[j]);
    }

    return answer;
}
