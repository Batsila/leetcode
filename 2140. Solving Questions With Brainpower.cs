public class Solution
{
    public long MostPoints(int[][] questions)
    {
        var dp = new long[questions.Count()];
        dp[^1] = questions[^1][0];

        for (var i = questions.Count() - 2; i >= 0; --i)
        {
            dp[i] = questions[i][0];

            if (i + questions[i][1] + 1 < questions.Count())
            {
                dp[i] += dp[i + questions[i][1] + 1 ];
            }

            dp[i] = Math.Max(dp[i], dp[i + 1]);
        }

        return dp[0];
    }
}