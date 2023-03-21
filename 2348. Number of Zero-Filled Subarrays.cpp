class Solution
{
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long ans = 0;
        long long curSize = 0;

        for (auto num : nums)
        {
            if (num)
            {
                curSize = 0;
            }
            else
            {
                ++curSize;
            }

            ans += curSize;
        }

        return ans;
    }
};