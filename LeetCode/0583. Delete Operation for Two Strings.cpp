class Solution 
{
    int dp[555][555];
public:
    int minDistance(string word1, string word2) 
    {     
        for (int i = 0; i <= word1.size(); ++i)
        {
            for (int j = 0; j <= word2.size(); ++j)
            {
                if (!i)
                {
                    dp[i][j] = j;
                }
                else if (!j)
                {
                    dp[i][j] = i;
                }
                else if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};