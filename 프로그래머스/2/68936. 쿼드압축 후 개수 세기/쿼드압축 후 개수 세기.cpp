#include <string>
#include <vector>

using namespace std;

struct Result
{
    void SetData(int number)
    {
        if (number & 1)
            ++one;
        else
            ++zero;

        ++count;
    }

    void PlusFrom(Result result)
    {
        one += result.one;
        zero += result.zero;
        count += result.count;

        result_one += result.result_one;
        result_zero += result.result_zero;

        before_one += result.before_one;
        before_zero += result.before_zero;
    }

    void Zip()
    {
        if (one == count)
        {
            before_one = one;
            result_one = 1;
        }
        else
        {
            if (0 == result_one)
                result_one = one;
        }
        
        if (zero == count)
        {
            before_zero = zero;
            result_zero = 1;
        }
        else
        {
            if (0 == result_zero)
                result_zero = zero;
        }
    }

    int one = 0;
    int zero = 0;

    int before_one = 0;
    int before_zero = 0;

    int result_one = 0;
    int result_zero = 0;

    int count = 0;
};

Result Recursive(const vector<vector<int>>& arr ,int start_x, int end_x, int start_y, int end_y)
{
    if (1 == end_x - start_x &&
        1 == end_y - start_y)
    {
        Result stResult;
        stResult.SetData(arr[start_x][start_y]);
        return  stResult;
    }
    
    Result _stResult;
    // 1구역
    _stResult.PlusFrom(Recursive(arr, start_x, end_x / 2 + (start_x / 2), start_y, end_y / 2 + (start_y / 2)));
    
    // 2구역
    _stResult.PlusFrom(Recursive(arr, end_x / 2 + (start_x / 2), end_x, start_y, end_y / 2 + (start_y / 2)));
     
    // 3구역
    _stResult.PlusFrom(Recursive(arr, start_x, end_x / 2 + (start_x / 2), end_y / 2 + (start_y / 2), end_y));

    // 4구역
    _stResult.PlusFrom(Recursive(arr, end_x / 2 + (start_x / 2), end_x, end_y / 2 + (start_y / 2), end_y));

    _stResult.Zip();

    return _stResult;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    Result stResult;
    stResult.PlusFrom(Recursive(arr, 0, arr.size(), 0, arr.size()));

    answer.push_back(stResult.result_zero);
    answer.push_back(stResult.result_one);

    return answer;
}
