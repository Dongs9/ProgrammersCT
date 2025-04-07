#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;

    uint64_t result_q1 = 0;
    uint64_t result_q2 = 0;

    queue<int> q1;
    queue<int> q2;

    for (int i = 0; i < queue1.size(); ++i)
    {
        result_q1 += queue1[i];
        q1.push(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); ++i)
    {
        result_q2 += queue2[i];
        q2.push(queue2[i]);
    }

    // 홀수면 ㅃㅃ
    if ((result_q1 + result_q2) & 1)
        return -1;

    int max_sequence = q1.size() + q2.size() + q1.size();
    int sequence = 0;
    while (true)
    {
        if (result_q1 == result_q2)
            return sequence;

        if (sequence == max_sequence)
            return -1;

        if (result_q1 > result_q2)
        {
            int pop = q1.front();
            q1.pop();

            result_q1 -= pop;

            q2.push(pop);

            result_q2 += pop;

            ++sequence;
        }
        else  if (result_q1 < result_q2)
        {
            int pop = q2.front();
            q2.pop();

            result_q2 -= pop;

            q1.push(pop);

            result_q1 += pop;

            ++sequence;
        }
    }

    return answer;
}
