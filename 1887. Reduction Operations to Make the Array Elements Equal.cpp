class Solution
{
public:
    int reductionOperations(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int steps = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i + 1] != nums[i])
            {
                ++steps;
            }

            ans += steps;
        }

        return ans;
    }
};