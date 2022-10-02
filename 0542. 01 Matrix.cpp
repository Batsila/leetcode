class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 12345));
        
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[i].size(); ++j)
            {
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    
                    if (j > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                    
                    if (i < dp.size() - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                    
                    if (j < dp[0].size() - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }
        
        for (int i = dp.size() - 1; i >= 0; --i)
        {
            for (int j = dp[i].size() - 1; j >= 0 ; --j)
            {
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    
                    if (j > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                    
                    if (i < dp.size() - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                    
                    if (j < dp[0].size() - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }
        
        return dp;
    }
};