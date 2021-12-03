class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int ans = nums[0];
        int min_t = nums[0];
        int max_t = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                int t = min_t;
                min_t = min(nums[i], max_t * nums[i]);
                max_t = max(nums[i], t * nums[i]);
            }
            else
            {
                min_t = min(nums[i], min_t * nums[i]);
                max_t = max(nums[i], max_t * nums[i]);
            }
            
            ans = max(ans, max_t);
        }
        
        return ans;
    }
};