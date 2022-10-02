class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        set<int> ms;
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (auto mine : mines)
        {
            ms.insert(mine[0] * 1000 + mine[1]);
        }
        
        for (int i = 0; i < n; ++i)
        {
            int lc = 0;
            
            for (int j = 0; j < n; ++j)
            {
                if (ms.find(i * 1000 + j) != ms.end())
                {
                    lc = 0;
                }
                else
                {
                    ++lc;
                }
                
                dp[i][j] = lc;
            }
            
            int rc = 0;
            
            for (int j = n - 1; j >= 0; --j)
            {
                if (ms.find(i * 1000 + j) != ms.end())
                {
                    rc = 0;
                }
                else
                {
                    ++rc;
                }
                
                dp[i][j] = min(dp[i][j], rc);
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i)
        {
            int uc = 0;
            
            for (int j = 0; j < n; ++j)
            {
                if (ms.find(j * 1000 + i) != ms.end())
                {
                    uc = 0;
                }
                else
                {
                    ++uc;
                }
                
                dp[j][i] = min(dp[j][i], uc);
            }
            
            int dc = 0;
            
            for (int j = n - 1; j >= 0; --j)
            {
                if (ms.find(j * 1000 + i) != ms.end())
                {
                    dc = 0;
                }
                else
                {
                    ++dc;
                }
                
                dp[j][i] = min(dp[j][i], dc);
                
                ans = max(ans, dp[j][i]);
            }
        }
        
        return ans;
    }
};