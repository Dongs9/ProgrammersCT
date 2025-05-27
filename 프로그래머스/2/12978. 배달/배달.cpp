#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {

    vector<vector<long long>> mm(N + 1, vector<long long>(N + 1, 2147483647));
    for (int i = 0; i <= N; ++i)
        mm[i][i] = 0;

    for (auto& data : road)
    {
        if (mm[data[0]][data[1]] > data[2])
            mm[data[0]][data[1]] = data[2];
        if (mm[data[1]][data[0]] > data[2])
            mm[data[1]][data[0]] = data[2];
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (mm[i][j] > mm[i][k] + mm[k][j])
                    mm[i][j] = mm[i][k] + mm[k][j];

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (mm[1][i] <= K)
        {
            cout << i << "번째 " << mm[1][i] << endl;
            ++answer;
        }
    }

    return answer;
}
