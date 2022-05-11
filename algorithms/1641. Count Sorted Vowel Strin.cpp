class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<int> dp(5, 1);
        
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 1; j < 5; ++j)
            {
                dp[j] += dp[j - 1];
            }
        }
        
        int ans = 0;
        
        for (int num : dp)
        {
            ans += num;
        }
        
        return ans;
    }
};