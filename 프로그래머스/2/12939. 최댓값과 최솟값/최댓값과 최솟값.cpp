#include <string>
#include <vector>

using namespace std;


string solution(string s) {

    int64_t min = 9223372036854775807;
    int64_t max = -9223372036854775807;

    string data = "";
    for (int i = 0; i < s.length(); ++i)
    {
        if (32 != s[i])
            data += s[i];
        else
        {
            int64_t value = std::atoll(data.c_str());

            if (value < min)
                min = value;

            if (value > max)
                max = value;

            data = "";
        }
    }

    int64_t value = std::atoll(data.c_str());

    if (value < min)
        min = value;

    if (value > max)
        max = value;

    string answer = std::to_string(min) + " " + std::to_string(max);
    return answer;
}
