using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        List<string> cards1List = cards1.ToList();
            List<string> cards2List = cards2.ToList();

            for(int i = 0; i < goal.Length; ++i)
            {
                if (cards1List.Count > 0 && goal[i].Equals(cards1List[0]))
                {
                    cards1List.RemoveAt(0);
                    continue;
                    
                }
                if(cards2List.Count > 0 && goal[i].Equals(cards2List[0]))
                {
                    cards2List.RemoveAt(0);
                    continue;
                }

                return "No";
            }

            return "Yes";
    }
}