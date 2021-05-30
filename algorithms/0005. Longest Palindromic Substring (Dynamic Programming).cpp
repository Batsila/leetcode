class Solution 
{
    bool dp[1000][1000];
public:
    string longestPalindrome(string s) 
    {
        int ans_l = 1;
        int ans_s = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = 1;
        }

        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                dp[i][i - 1] = 1;
                ans_l = 2;
                ans_s = i - 1;
            }
        }

        for (int i = 2; i < s.size(); ++i)
        {
            for (int j = i - 2; j >= 0; --j)
            {
                dp[i][j] = dp[i - 1][j + 1] && s[i] == s[j];

                if (dp[i][j] && i - j + 1 > ans_l)
                {
                    ans_l = i - j + 1;
                    ans_s = j;
                }
            }
        }
        
        return s.substr(ans_s, ans_l);
    }
};