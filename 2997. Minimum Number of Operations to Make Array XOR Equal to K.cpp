class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        int nums_xor = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            nums_xor ^= nums[i];
        }

        int ans = 0;

        for (int i = 0; i < 32; ++i)
        {
            if ((k >> i & 1) != (nums_xor >> i & 1))
            {
                ++ans;
            }
        }

        return ans;
    }
};