#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
set<string> result;

bool Check(int target_x, int target_y , int row, int col)
{
    if (target_y == col)
        return true;

    if (target_x == row)
        return true;

    if (abs(target_x - row) == abs(target_y - col))
        return true;
   
    return false;
}

void Recursive(vector<pair<int, int>>& path, int n, int index)
{
    if (n == index)
    {
        std::sort(path.begin(), path.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
            });

        string str;
        for (auto& pair : path)
            str += "(" + to_string(pair.second) + ")";
        result.insert(str);
        
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        bool bContinue = false;
        for (int j = 0; j < index; ++j)
        {
            if (true == Check(path[j].first, path[j].second, index, i))
            {
                bContinue = true;
                break;
            }
        }

        if (true == bContinue)
            continue;

        path[index] = { index , i };
        Recursive(path, n, index + 1);
    }
}

int solution(int n) {
    
    if (1 == n)
        return 1;
    
    if (n < 4)
        return 0;

    vector<pair<int, int>> path;
    for (int i = 0; i < n; ++i)
        path.push_back({ 0,0 });

    Recursive(path, n, 0);

    return result.size();
}