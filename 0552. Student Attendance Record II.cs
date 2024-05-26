public class Solution
{
    private const int MOD = 1_000_000_007;

    public int CheckRecord(int n)
    {
        var dp = new int[n + 1, 2, 3];
        dp[0, 0, 0] = 1;

        for (var currentDay = 1; currentDay <= n; ++currentDay)
        {
            for (var absentDays = 0; absentDays < 2; ++absentDays)
            {
                for (var lateDays = 0; lateDays < 3; ++lateDays)
                {
                    // Present
                    dp[currentDay, absentDays, 0] += dp[currentDay - 1, absentDays, lateDays];
                    dp[currentDay, absentDays, 0] %= MOD;

                    // Absent
                    if (absentDays < 1)
                    {
                        dp[currentDay, absentDays + 1, 0] += dp[currentDay - 1, absentDays, lateDays];
                        dp[currentDay, absentDays + 1, 0] %= MOD;
                    }

                    // Late
                    if (lateDays < 2)
                    {
                        dp[currentDay, absentDays, lateDays + 1] += dp[currentDay - 1, absentDays, lateDays];
                        dp[currentDay, absentDays, lateDays + 1] %= MOD;
                    }
                }
            }
        }

        var result = 0;

        for (var absentDays = 0; absentDays < 2; ++absentDays)
        {
            for (var lateDays = 0; lateDays < 3; ++lateDays)
            {
                result += dp[n, absentDays, lateDays];
                result %= MOD;
            }
        }

        return result;
    }
}