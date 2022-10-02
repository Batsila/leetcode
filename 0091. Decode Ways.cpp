class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.size() == 0 or s[0] == '0')
        {
            return 0;
        }
        
        vector<long> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] != '0')
            {
                dp[i + 1] += dp[i];
            }
                
            if (s[i - 1] == '1')
            {
                dp[i + 1] += dp[i - 1];
            }
                
            if (s[i - 1] == '2' and s[i] <= '6')
            {
                dp[i + 1] += dp[i - 1];
            }
        }
        
        return dp[s.size()];
    }
};