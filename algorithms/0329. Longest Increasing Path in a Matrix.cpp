class Solution 
{
    int dp[200][200];
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int ans = 0;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                ans = max(ans, dfs(i, j, -1, matrix));
            }
        }
        
        return ans;
    }
    
    int dfs(int i, int j, int p, vector<vector<int>>& matrix)
    {
        if (i < 0
            or j < 0
            or i >= matrix.size()
            or j >= matrix[0].size()
            or matrix[i][j] <= p)
        {
            return 0;
        }
        
        if (dp[i][j])
        {
            return dp[i][j];
        }
        
        dp[i][j] = max(dp[i][j], dfs(i, j + 1, matrix[i][j], matrix) + 1);
        dp[i][j] = max(dp[i][j], dfs(i + 1, j, matrix[i][j], matrix) + 1);
        dp[i][j] = max(dp[i][j], dfs(i, j - 1, matrix[i][j], matrix) + 1);
        dp[i][j] = max(dp[i][j], dfs(i - 1, j, matrix[i][j], matrix) + 1);
        
        return dp[i][j];
    }
};