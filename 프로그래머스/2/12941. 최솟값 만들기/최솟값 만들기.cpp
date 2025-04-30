#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    std::sort(A.begin() , A.end() , [](const auto v1 , const auto v2)
              { return v1 > v2; });
    
    std::sort(B.begin() , B.end() , [](const auto v1 , const auto v2)
              { return v1 < v2; });
    
    for ( int i  = 0; i < A.size(); ++i)
        answer += A[i] * B[i];
    
    return answer;
}