class Solution 
{
    int dp[1000];
public:
    int jump(vector<int>& nums) 
    {
        dp[0] = 1;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (dp[i])
            {
                for (int j = 1; j <= nums[i]; ++j)
                {
                    if (i + j < nums.size())
                    {
                        if (!dp[i + j])
                        {
                            dp[i + j] = dp[i] + 1;
                        }
                        else
                        {
                            dp[i + j] = min(dp[i + j], dp[i] + 1);
                        }
                    }
                }
            }
        }
        
        return dp[nums.size() - 1] - 1;
    }
};