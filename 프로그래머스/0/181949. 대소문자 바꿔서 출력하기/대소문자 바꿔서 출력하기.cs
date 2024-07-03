using System;

public class Example
{
    public static void Main()
    {
        String s;
            String end = "";

            Console.Clear();
            s = Console.ReadLine();

            int big = 65;
            int small = 97;
            int minus = small - big;
            for (int i = 0; i < s.Length; ++ i)
            {
                int cur = Convert.ToInt32(s[i]);
                if (small <= cur)
                {
                    end += ((char)(cur - minus)).ToString();
                }
                else
                {
                    end += ((char)(cur + minus)).ToString();
                }
            }

            Console.Write(end);
    }
}