class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            currentSum = max(currentSum + nums[i], nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};