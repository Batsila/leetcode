class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (target <= nums[0])
        {
            return 0;
        }
        
        int l = 0;
        int r = nums.size() - 1;
        
        while (r > l)
        {
            int c = (r + l) / 2;
            
            if (target > nums[c])
            {
                l = c + 1;
            }
            else if (target < nums[c])
            {
                r = c - 1;
            }
            else
            {
                return c;
            }
        }
        
        return target <= nums[r] ? r : r + 1;
    }
};