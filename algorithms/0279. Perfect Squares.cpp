class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        int num = 1;
        
        while (num * num <= n)
        {
            int s = num * num;
            
            for (int i = s; i <= n; ++i)
            {
                dp[i] = min(dp[i], dp[i - s] + 1);
            }
            
            ++num;
        }
        
        
        return dp[n];
    }
};