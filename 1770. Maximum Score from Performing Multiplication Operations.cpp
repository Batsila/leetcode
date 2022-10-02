class Solution
{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        vector<vector<int>> dp(
            multipliers.size() + 1,
            vector<int>(multipliers.size() + 1, 0));
        
        for (int i = multipliers.size() - 1; i >= 0; --i)
        {
            for (int j = i; j >= 0; --j)
            {
                dp[i][j] = max(
                    multipliers[i] * nums[j] + dp[i + 1][j + 1],
                    multipliers[i] * nums[nums.size() - 1 - i + j] + dp[i + 1][j]);
            }
        }
        
        return dp[0][0];
    }
};