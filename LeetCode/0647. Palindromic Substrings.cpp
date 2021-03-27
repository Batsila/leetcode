class Solution 
{
    bool dp[1000][1000];
public:
    int countSubstrings(string s) 
    {
        int ans = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = 1;
            ++ans;
        }
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                dp[i][i - 1] = 1;
                ++ans;
            }
        }
        
        for (int i = 2; i < s.size(); ++i)
        {
            for (int j = i - 2; j >= 0; --j)
            {
                if (dp[i - 1][j + 1] && s[i] == s[j])
                {
                    dp[i][j] = 1;
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};