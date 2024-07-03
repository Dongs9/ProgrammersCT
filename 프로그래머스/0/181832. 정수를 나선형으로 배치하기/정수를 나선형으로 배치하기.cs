using System;

        enum state
        {
            left,
            right,
            up,
            down
        };
public class Solution {
    public int[,] solution(int n) {
            int[,] answer = new int[n, n];

            int count = 1;

            int data = 1;
            int x = -1, y = 0;

            state state = state.right;

            while (data <= n * n)
            {

                switch (state)
                {
                    case state.left:
                        {
                            if (x > count - 1)
                                x--;
                            else
                            {
                                state = state.up;
                                continue;
                            }
                        }
                        break;
                    case state.right:
                        {
                            if (x < n - count)
                                x++;
                            else
                            {
                                state = state.down;
                                continue;
                            }
                        }
                        break;
                    case state.up:
                        {
                            if (y > count)
                                y--;
                            else
                            {
                                state = state.right;
                                count++;
                                continue;
                            }
                        }
                        break;
                    case state.down:
                        {
                            if (y < n - count)
                                y++;
                            else
                            {
                                state = state.left;
                                continue;
                            }
                        }
                        break;
                    default:
                        break;
                }

                answer[y, x] = data++;
            }
        return answer;
    }
}