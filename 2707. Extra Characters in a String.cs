public class Solution
{
    public int MinExtraChar(string s, string[] dictionary)
    {
        var wordsSet = dictionary.ToHashSet();
        var dp = new int[s.Length + 1];

        for (var left = s.Length - 1; left >= 0; --left)
        {
            dp[left] = dp[left + 1] + 1;

            for (var right = left + 1; right <= s.Length; ++right)
            {
                if (wordsSet.Contains(s[left..right]))
                {
                    dp[left] = Math.Min(dp[left], dp[right]);
                }
            }
        }

        return dp[0];
    }
}