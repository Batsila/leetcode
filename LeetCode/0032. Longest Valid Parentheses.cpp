class Solution 
{
    int dp[30000];
public:
    int longestValidParentheses(string s) 
    { 
        int ans = 0;
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                }
                else
                {
                    int j = i - dp[i - 1] - 1;
                    
                    if (j >= 0 && s[j] == '(')
                    {
                        dp[i] = dp[i - 1] + 2 + (j - 1 >= 0 ? dp[j - 1] : 0);
                    }
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};