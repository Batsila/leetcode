class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int max_i = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (max_i < i)
            {
                return false;
            }
            
            max_i = max(max_i, i + nums[i]);
            
            if (max_i >= nums.size() - 1)
            {
                return true;
            }
        }
        
        return true;
    }
};