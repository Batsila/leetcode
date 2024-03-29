class Solution
{
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int max_value = *max_element(nums.begin(), nums.end());
        vector<int> max_value_indexes;
        long long ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == max_value)
            {
                max_value_indexes.push_back(i);
            }

            if (max_value_indexes.size() >= k)
            {
                ans += max_value_indexes[max_value_indexes.size() - k] + 1;
            }
        }

        return ans;
    }
};