class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r)
        {
            int m = (l + r) / 2;
            
            if (nums[m] == target)
            {
                return true;
            }
            
            if (nums[l] == nums[m] and nums[r] == nums[m])
            {
                ++l;
                --r;
            }
            else if (nums[l] <= nums[m])
            {
                if (nums[l] <= target and nums[m] > target)
                {
                    r = m - 1;
                } 
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if (nums[m] < target and nums[r] >= target)
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        
        return false;
    }
};