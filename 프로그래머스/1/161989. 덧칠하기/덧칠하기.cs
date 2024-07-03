using System;
using System.Linq;

public class Solution {
    public int solution(int n, int m, int[] section) {
int answer = 0;
            bool[] arr = Enumerable.Repeat(true, n + 1).ToArray();

            for(int i = 0; i <section.Length; ++i)
            {
                arr[section[i]] = false;
            }

            for (int i = 0; i < section.Length; ++i)
            {
                if (arr[section[i]] == true)
                {
                    continue;
                }

                for (int j = 0; j < m; ++j)
                {
                    if (section[i] + j > n)
                        break;

                    if (arr[section[i] + j] == false)
                    {
                        arr[section[i] + j] = true;
                    }
                }

                answer++;
            }

            return answer;
    }
}