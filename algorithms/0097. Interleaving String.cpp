class Solution
{
    bool dp[101][101];
    
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        
        for (int i = 0; i < s1.size() + 1; ++i)
        {
            for (int j = 0; j < s2.size() + 1; ++j)
            {
                if (i == 0 and j == 0)
                {
                    dp[0][0] = 1;
                }
                else if (i == 0)
                {
                    dp[0][j] = dp[0][j - 1] and (s2[j - 1] == s3[j - 1]);
                }
                else if (j == 0)
                {
                    dp[i][0] = dp[i - 1][0] and (s1[i - 1] == s3[i - 1]);
                }
                else
                {
                    dp[i][j] = (dp[i][j - 1] and (s2[j - 1] == s3[i + j - 1]))
                        or (dp[i - 1][j] and (s1[i - 1] == s3[i + j - 1]));
                }
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
};