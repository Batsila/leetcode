class Solution 
{
public:
    bool checkPossibility(vector<int>& nums) 
    {
        bool m = 0;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                if (m)
                {
                    return false;
                }
                
                m = 1;
                
                if (i >= 2 and nums[i - 2] > nums[i])
                {
                    nums[i] = nums[i - 1];
                }
            }
        }
        
        return true;
    }
};