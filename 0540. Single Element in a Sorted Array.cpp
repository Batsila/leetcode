class Solution
{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 2;
        
        while (l <= r)
        {
            int m = (l + r) / 2;
            
            if (nums[m ^ 1] == nums[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        return nums[l];
    }
};