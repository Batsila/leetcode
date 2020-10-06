class Solution 
{
    public int MinCostClimbingStairs(int[] cost) 
    {
        var dp = new int[cost.Count() + 1];
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < cost.Count(); ++i)
        {
            dp[i] = cost[i] + Math.Min(dp[i - 1], dp[i - 2]);
        }
        
        return Math.Min(dp[cost.Count() - 1], dp[cost.Count() - 2]);
    }
}