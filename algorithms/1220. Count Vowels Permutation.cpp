class Solution
{
    long dp[20000][5];
public:
    int countVowelPermutation(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (i == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    switch (j)
                    {
                        case 0:
                        {
                            dp[i][0] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4];
                            break;
                        }
                        case 1:
                        {
                            dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
                            break;
                        }
                        case 2:
                        {
                            dp[i][2] = dp[i - 1][1] + dp[i - 1][3];
                            break;
                        }
                        case 3:
                        {
                            dp[i][3] = dp[i - 1][2];
                            break;
                        }
                        case 4:
                        {
                            dp[i][4] = dp[i - 1][2] + dp[i - 1][3];
                            break;
                        }
                    }
                    
                    dp[i][j] %= 1000000007;
                }
            }
        }
        
        long ans = 0;
        
        for (int i = 0; i < 5; ++i)
        {
            ans += dp[n - 1][i];
            ans %= 1000000007;
        }
        
        return ans;
    }
};