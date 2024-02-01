class Solution
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() / 3; ++i)
        {
            if (nums[i * 3 + 2] - nums[i * 3] <= k)
            {
                ans.push_back({nums[i * 3], nums[i * 3 + 1], nums[i * 3 + 2]});
            }
            else
            {
                return {};
            }
        }

        return ans;
    }
};