#include <string>
#include <vector>

#include <algorithm>
#include <chrono>
#include <stack>

using namespace std;

std::tm Parse_Time(string& time_string)
{
    size_t pos = time_string.find(':');
    int hour = std::stoi(time_string.substr(0, pos));
    int minute = std::stoi(time_string.substr(pos + 1));

    std::time_t now = std::time(nullptr);
    std::tm tmNow{};
    localtime_r(&now, &tmNow);

    tmNow.tm_hour = hour;
    tmNow.tm_min = minute;
    tmNow.tm_sec = 0;

    return tmNow;
}

int Calc_Gap(string& str1 , string& str2)
{
    std::tm cur = Parse_Time(str1);
    std::tm next = Parse_Time(str2);

    time_t time1 = std::mktime(&cur);
    time_t time2 = std::mktime(&next);

    return std::difftime(time2, time1) / 60;
}

string Plus_Time(string& str1, int time)
{
    std::tm cur = Parse_Time(str1);

    cur.tm_min += time;
    
    return to_string(cur.tm_hour) + ":" + to_string(cur.tm_min);
}

vector<string> solution(vector<vector<string>> plans) 
{
    vector<string> answer;

    std::sort(plans.begin(), plans.end() ,[](const auto& a , const auto& b)
    {
            return a[1] < b[1];
    });

    stack<vector<string>> insert_data;
    stack<vector<string>> que_plans;
    for (int i = plans.size() - 1; i > -1; --i)
        que_plans.push(plans[i]);

    while (true)
{
    auto cur = que_plans.top();
    que_plans.pop();

    if (que_plans.empty())
    {
        answer.push_back(cur[0]);
        break;
    }

    int need_time = std::atoi(cur[2].c_str());

    auto& next = que_plans.top();

    int gap = Calc_Gap(cur[1], next[1]);

    if (need_time > gap)
    {
        cur[2] = std::to_string(need_time - gap);
        insert_data.push(cur);
    }
    else
    {
        answer.push_back(cur[0]);

        if (false == insert_data.empty())
        {
            auto& next1 = insert_data.top();
            int need_time2 = atoi(next1[2].c_str());

            int need_time3 = gap - need_time;
            if (need_time3 > 0)
            {
                next1[1] = Plus_Time(cur[1], need_time);
                que_plans.push(next1);
                insert_data.pop();
            }
            else
            {
                next1[1] = Plus_Time(cur[1], need_time);
            }
        }
    }
}

    while (!insert_data.empty())
    {
        auto& data = insert_data.top();
        answer.push_back(data[0]);
        insert_data.pop();
    }
    
    return answer;
}