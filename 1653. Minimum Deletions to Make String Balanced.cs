public class Solution
{
    public int MinimumDeletions(string s)
    {
        var result = 0;
        var bCount = 0;

        foreach (var c in s)
        {
            if (c is 'b')
            {
                ++bCount;
            }
            else
            {
                result = Math.Min(result + 1, bCount);
            }
        }

        return result;
    }
}