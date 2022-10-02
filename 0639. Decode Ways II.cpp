class Solution
{
public:
    int numDecodings(string s)
    {
        vector<long> dp(s.size() + 1);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == '*')
            {
                dp[i + 1] = 9 * dp[i] % 1000000007;
                
                if (s[i - 1] == '1' or s[i - 1] == '*')
                {
                    dp[i + 1] += 9 * dp[i - 1];
                    dp[i + 1] %= 1000000007;
                }
                
                if (s[i - 1] == '2' or s[i - 1] == '*')
                {
                    dp[i + 1] += 6 * dp[i - 1];
                    dp[i + 1] %= 1000000007;
                }
            }
            else
            {
                dp[i + 1] = s[i] != '0' ? dp[i] : 0;
                
                if (s[i - 1] == '1' or s[i - 1] == '*')
                {
                    dp[i + 1] += dp[i - 1];
                    dp[i + 1] %= 1000000007;
                }
                
                if ((s[i - 1] == '2' or s[i - 1] == '*') and s[i] <= '6')
                {
                    dp[i + 1] += dp[i - 1];
                    dp[i + 1] %= 1000000007;
                }
            }
        }
        
        return dp[s.size()];
    }
};