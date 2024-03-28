class Solution
{
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> freqs;
        int l = 0;
        int r = 0;

        while (r < nums.size())
        {
            ++freqs[nums[r]];

            while (freqs[nums[r]] > k)
            {
                --freqs[nums[l]];
                ++l;
            }

            ++r;
            ans = max(ans, r - l);
        }

        return ans;
    }
};