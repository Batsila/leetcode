class Solution
{
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }

private:
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> nums_freqs;
        int l = 0;
        int r = 0;

        while (r < nums.size())
        {
            nums_freqs[nums[r]]++;

            while (nums_freqs.size() > k)
            {
                if (nums_freqs[nums[l]] > 1)
                {
                    nums_freqs[nums[l]]--;
                }
                else
                {
                    nums_freqs.erase(nums[l]);
                }

                ++l;
            }

            ans += r - l + 1;
            ++r;
        }

        return ans;
    }
};