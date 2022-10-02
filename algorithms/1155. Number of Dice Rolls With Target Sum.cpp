class Solution
{
    int dp[1111][33];
public:
    int numRollsToTarget(int n, int k, int target)
    {
        for (int i = 1; i <= k; ++i)
        {
            dp[i][1] = 1;
        }
        
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                for (int t = 1; t <= target; ++t)
                {
                    dp[t + j][i] += dp[t][i - 1];
                    dp[t + j][i] %= 1000000007;
                }
            }
        }
        
        return dp[target][n];
    }
};