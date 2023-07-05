class Solution
{
public:
    int longestSubarray(vector<int>& nums)
    {
        int zeros = 0;
        int ans = 0;
        int start = 0;
        
        for (int end = 0; end < nums.size(); ++end)
        {
            if (nums[end] == 0)
            {
                ++zeros;
            }

            while (zeros > 1)
            {
                if (nums[start] == 0)
                {
                    --zeros;   
                }

                ++start;
            }

            ans = max(ans, end - start);
        }

        return ans;
    }
};