class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> ans;

        for (int num : nums)
        {
            if (nums[abs(num) - 1] > 0)
            {
                nums[abs(num) - 1] *= -1;
            }
            else
            {
                ans.push_back(abs(num));
            }
        }

        return ans;
    }
};