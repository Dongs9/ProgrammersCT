#include <string>
#include <vector>
#include <list>
using namespace std;

vector<int> solution(int n, long long k) 
{
    vector<long long> vec = { 1 };
    vec.reserve(n);

    list<int> numbers;
    for (int i = 1; i <= n; ++i)
        numbers.push_back(i);

    for (int i = 1; i <= n; ++i)
        vec.push_back(vec[i - 1] * i);

    vector<int> answer;

    --k;

    long long a1 = k;
    for (int i = 1; i < n; ++i)
    {
        long long a = a1 / vec[n - i];
        a1 %= vec[n - i];

        auto iter = numbers.begin();
        std::advance(iter, a);
        answer.push_back(*iter);
        numbers.remove(*iter);   
    }

    answer.push_back(numbers.front());

    return answer;
}