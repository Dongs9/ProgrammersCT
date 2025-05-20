#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

struct stRobot
{
    int x = 0;
    int y = 0;

    int end_x = 0;
    int end_y = 0;

    queue<int> end_x_que;
    queue<int> end_y_que;

    bool bEnd = false;

    void Move()
    {
        if (end_x > x)
        {
            x += 1;
            return;
        }
        else if (end_x < x)
        {
            x -= 1;
            return;
        }
        else if (end_y > y)
        {
            y += 1;
            return;
        }
        else if (end_y < y)
        {
            y -= 1;
            return;
        }

        if (false == end_x_que.empty())
        {
            end_x = end_x_que.front();
            end_x_que.pop();

            end_y = end_y_que.front();
            end_y_que.pop();

            if (end_x > x)
            {
                x += 1;
                return;
            }
            else if (end_x < x)
            {
                x -= 1;
                return;
            }
            else if (end_y > y)
            {
                y += 1;
                return;
            }
            else if (end_y < y)
            {
                y -= 1;
                return;
            }
        }

        bEnd = true;
    }
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) 
{
    int crash_count = 0;

    int robot_count = routes.size();

    unordered_map<pair<int, int>, int, pair_hash> map;
    map.reserve(robot_count);

    bool bFirst = true;

    vector<stRobot> robots;
    robots.reserve(robot_count);

    int sequence = 0;
    while (true)
    {
        for (int i = 0; i < robot_count; ++i)
        {
            if (sequence == 0)
            {
                int start_index = routes[i][0];
                int end_index = routes[i][1];

                stRobot robot;
                robot.x = points[start_index - 1][0];
                robot.y = points[start_index - 1][1];
                robot.end_x = points[end_index - 1][0];
                robot.end_y = points[end_index - 1][1];

                for (int j = 2; j < routes[i].size(); ++j)
                {
                    int end_index = routes[i][j];
                    robot.end_x_que.push(points[end_index - 1][0]);
                    robot.end_y_que.push(points[end_index - 1][1]);
                }

                robots.push_back(robot);
            }

            if (true == robots[i].bEnd)
                continue;

            map[{robots[i].x, robots[i].y}] += 1;

            robots[i].Move();
        }

        if (map.empty())
            break;

        for (auto& pos : map)
        {
            if (pos.second > 1)
                ++crash_count;
        }

        map.clear();

        ++sequence;
    }

    return crash_count;
}