public class Solution
{
    public bool WordBreak(string s, IList<string> wordDict)
    {
        var words = new HashSet<string>(wordDict);
        var dp = new bool[s.Length + 1];
        dp[0] = true;

        for (int i = 1; i < s.Length + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && words.Contains(s[j..i]))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[^1];
    }
}