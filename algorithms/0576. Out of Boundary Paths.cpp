class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[startRow][startColumn] = 1;
        int ans = 0;
        
        for (int moves = 1; moves <= maxMove; ++moves)
        {
            vector<vector<int>> t(m, vector<int>(n, 0));
            
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i == 0)
                    {
                        ans += dp[i][j];
                        ans %= 1000000007;
                    }
                    
                    if (j == 0)
                    {
                        ans += dp[i][j];
                        ans %= 1000000007;
                    }
                    
                    if (i == m - 1)
                    {
                        ans += dp[i][j];
                        ans %= 1000000007;
                    }
                    
                    if (j == n - 1)
                    {
                        ans += dp[i][j];
                        ans %= 1000000007;
                    }
                    
                    t[i][j] += i > 0 ? dp[i - 1][j] : 0;
                    t[i][j] %= 1000000007;
                    
                    t[i][j] += j > 0 ? dp[i][j - 1] : 0;
                    t[i][j] %= 1000000007;
                    
                    t[i][j] += i < m - 1 ? dp[i + 1][j] : 0;
                    t[i][j] %= 1000000007;
                    
                    t[i][j] += j < n - 1 ? dp[i][j + 1] : 0;
                    t[i][j] %= 1000000007;
                }
            }
            
            dp = t;
        }
        
        return ans;
    }
};