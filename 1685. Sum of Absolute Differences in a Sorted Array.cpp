class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums)
    {
        vector<int> prefixSum(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            prefixSum[i] = i == 0 ? nums[i] : nums[i] + prefixSum[i - 1];
        }

        vector<int> ans(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            ans[i] += i * nums[i] - (prefixSum[i] - nums[i]);
            ans[i] += (prefixSum[nums.size() - 1] - prefixSum[i]) - (nums.size() - 1 - i) * nums[i];
        }

        return ans;
    }
};