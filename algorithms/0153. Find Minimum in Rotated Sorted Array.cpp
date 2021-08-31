class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        
        if (nums[l] <= nums[r])
        {
            return nums[l];
        }
        
        while (l < r)
        {
            int m = (l + r) / 2;
            
            if (nums[m] > nums[m + 1])
            {
                return nums[m + 1];
            }
            
            if (nums[m - 1] > nums[m])
            {
                return nums[m];
            }
            
            if (nums[m] > nums[l])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        return 42;
    }
};