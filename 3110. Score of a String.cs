public class Solution
{
    public int ScoreOfString(string s)
    {
        var result = 0;

        for (int i = 1; i < s.Length; ++i)
        {
            result += Math.Abs(s[i - 1] - s[i]);
        }

        return result;
    }
}