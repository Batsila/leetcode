public class Solution
{
    public int MinSwaps(string s)
    {
        var openingBracketsCount = 0;

        foreach (var c in s)
        {
            if (c == '[')
            {
                ++openingBracketsCount;
            }
            else if (openingBracketsCount > 0)
            {
                --openingBracketsCount;
            }
        }

        return (openingBracketsCount + 1) / 2;
    }
}