#include <string>
#include <vector>

using namespace std;

int solution(int n) {
int answer = 0;

if (n == 2)
    return 1;

vector<uint64_t> vec(n, 0);

vec[1] = 1;
vec[2] = 1;

int a = 1234567;
for (int i = 3; i < n; ++i)
{
    vec[i] = (vec[i - 1] + vec[i - 2]) % a;
}

answer = (vec[n - 1] + vec[n - 2]) % a;//(vec[n - 1] % a) + (vec[n - 2] % a);
return answer;
}