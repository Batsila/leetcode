class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 1);
        vector<int> pred(nums.size(), -1);
        
        int pi = 0;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    pred[i] = j;
                }
            }
            
            if (dp[i] > dp[pi])
            {
                pi = i;
            }
        }
        
        vector<int> ans;
        
        while (pi >= 0)
        {
            ans.push_back(nums[pi]);
            pi = pred[pi];
        }
        
        return ans;
    }
};