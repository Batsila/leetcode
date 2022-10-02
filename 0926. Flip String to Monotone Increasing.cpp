class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(2, 100000));
        
        dp[0][0] = s[0] == '0' ? 0 : 1;
        dp[0][1] = s[0] == '1' ? 0 : 1;
        
        for (int i = 1; i < s.size(); ++i)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][0] += s[i] == '0' ? 0 : 1;
            
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] += s[i] == '1' ? 0 : 1;
        }
        
        return min(dp[s.size() - 1][0], dp[s.size() - 1][1]);
    }
};