class Solution
{
public:
    vector<int> getAverages(vector<int>& nums, int k)
    {
        vector<int> ans(nums.size(), -1);

        if (2 * k + 1 > nums.size())
        {
            return ans;
        }

        long long sum = 0;

        for (int i = 0; i < 2 * k + 1; ++i)
        {
            sum += nums[i];
        }

        ans[k] = sum / (2 * k + 1);

        for (int i = 2 * k + 1; i < nums.size(); ++i)
        {
            sum += nums[i] - nums[i - 2 * k - 1];
            ans[i - k] = sum / (2 * k + 1);
        }

        return ans;
    }
};