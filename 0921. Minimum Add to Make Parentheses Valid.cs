public class Solution
{
    public int MinAddToMakeValid(string s)
    {
        var openingCount = 0;
        var closingCount = 0;

        foreach (var c in s)
        {
            if (c == '(')
            {
                ++openingCount;
            }
            else 
            {
                if (openingCount > 0)
                {
                    --openingCount;
                }
                else
                {
                    ++closingCount;
                }
            }
        }

        return openingCount + closingCount;
    }
}