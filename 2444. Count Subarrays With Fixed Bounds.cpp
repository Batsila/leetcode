class Solution
{
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        long long ans = 0;
        int min_l = -1;
        int max_l = -1;
        int l = -1;

        for (int r = 0; r < nums.size(); ++r)
        {
            if (nums[r] < minK or nums[r] > maxK)
            {
                l = r;
            }

            if (nums[r] == minK)
            {
                min_l = r;
            }

            if (nums[r] == maxK)
            {
                max_l = r;
            }

            ans += max(0, min(min_l, max_l) - l);
        }

        return ans;
    }
};