class Solution 
{
    unsigned long long dp[1001];
public:
    unsigned long long combinationSum4(vector<int>& nums, int target) 
    {
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i)
        {
            for (int num : nums)
            {
                dp[i] += i - num >= 0 ? dp[i - num] : 0;
            }
        }
        
        return dp[target];
    }
};