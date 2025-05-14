#include <string>
#include <vector>
#include <set>

using namespace std;

multiset<int> result;

int RecursiveFunc(vector<string>& maps, int row, int col)
{
    if ('X' == maps[row][col])
        return 0;

    int return_value = maps[row][col] - '0';
    maps[row][col] = 'X';

    if (-1 < col + 1 && col + 1 < maps[0].length())
        return_value += RecursiveFunc(maps, row, col + 1);
    
    if (-1 < col - 1 && col - 1 < maps[0].length())
        return_value += RecursiveFunc(maps, row, col - 1);

    if (-1 < row + 1 && row + 1 < maps.size())
        return_value += RecursiveFunc(maps, row + 1, col);
    
    if (-1 < row - 1 && row - 1 < maps.size())
        return_value += RecursiveFunc(maps, row - 1, col);

    return return_value;
}

vector<int> solution(vector<string> maps) {

    int row_size = maps.size();
    int col_size = maps[0].length();
    int max_size = row_size * col_size;

        for (int row = 0; row < row_size; ++row)
        for (int col = 0; col < col_size; ++col)
        {
            if ('X' == maps[row][col])
                continue;

            int value = RecursiveFunc(maps, row, col);
            if (0 == value)
                continue;

            result.insert(value);
        }

    if (result.empty())
        return { -1 };
    
    vector<int> answer(result.begin(), result.end());
    return answer;
}