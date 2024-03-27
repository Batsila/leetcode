class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int ans = 0;
        
        if (k > 1)
        {
            int l = 0;
            int r = 0;
            int product = 1;

            while (r < nums.size())
            {
                product *= nums[r];

                while (product >= k)
                {
                    product /= nums[l];
                    ++l;
                }

                ans += r - l + 1;

                ++r;
            }
        }

        return ans;
    }
};