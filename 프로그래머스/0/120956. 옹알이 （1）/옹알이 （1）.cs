using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] babbling) {
        int answer = 0;
        
            string[] data = { "aya", "ye", "woo", "ma" };
            for (int i = 0; i < babbling.Length; ++i)
            {
                string temp = babbling[i];
                bool isPass = true;
                for (int k = 0; k < data.Length; ++k)
                {
                    string[] tempCount = temp.Split(data[k], StringSplitOptions.None);
                    if (tempCount.Length > 2)
                    {
                        isPass = false;
                        break;
                    }
                    else
                    {
                        temp = temp.Replace(data[k], " ");
                    }
                }

                if (isPass && String.IsNullOrWhiteSpace(temp))
                {
                    ++answer;
                }
            }
        
        return answer;
    }
}