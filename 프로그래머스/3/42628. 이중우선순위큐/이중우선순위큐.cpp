#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) 
{
    map<int, int> queue_map;
    for (auto& data : operations)
    {
        if ('I' == data[0])
        {
           int number = atoi(data.substr(2, data.length() - 1).c_str());

           if (queue_map.end() != queue_map.find(number))
               ++queue_map[number];
           else
               queue_map[number] = 1;
        }
        else
        {
            // 최댓값 삭제
            if ('1' == data[2])
            {
                if (queue_map.empty())
                    continue;

                auto iter = queue_map.end();
                int first = (*(--iter)).first;
                int second = (*iter).second;
                if (second > 1)
                    queue_map[first]--;
                else
                    queue_map.erase(first);
            }
            // 최솟값 삭제
            else
            {
                if (queue_map.empty())
                    continue;

                auto iter = queue_map.begin();
                int first = (*iter).first;
                int second = (*iter).second;
                if (second > 1)
                    queue_map[first]--;
                else
                    queue_map.erase(first);
            }
        }
    }

    if (queue_map.empty())
        return { 0,0 };

    if (queue_map.size() == 1)
    {
        if ((*queue_map.begin()).second > 1)
            return { (*queue_map.begin()).first , (*queue_map.begin()).first };
    }

    return { (*(--queue_map.end())).first , (*queue_map.begin()).first };
}