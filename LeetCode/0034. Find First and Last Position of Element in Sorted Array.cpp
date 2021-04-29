class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int li = -1;
        int ri = -1;
        
        int l = 0;
        int r = nums.size() - 1;
        
        while (r >= l)
        {
            int m = (r + l) / 2;
            
            if (nums[m] == target)
            {
                li = m;
                r = m - 1;
            }
            else if (target > nums[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            } 
        }
        
        l = 0;
        r = nums.size() - 1;
        
        while (r >= l)
        {
            int m = (r + l) / 2;
            
            if (nums[m] == target)
            {
                ri = m;
                l = m + 1;
            }
            else if (target > nums[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            } 
        }
        
        return vector<int> { li, ri };
    }
};