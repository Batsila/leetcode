class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int zc = 0;
        int zi;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!nums[i])
            {
                zi = i;
                ++zc;
            }
        }
        
        vector<int> ans(nums.size(), 0);
        
        if (zc > 1)
        {
            return ans;
        }
        else if (zc == 1)
        {
            int m = 1;
            
            for (int i = 0; i < nums.size(); ++i)
            {
                if (i != zi)
                {
                    m *= nums[i];
                }
            }
            
            ans[zi] = m;
            
            return ans;
        }
        else
        {
            int m = 1;
            
            for (int i = 0; i < nums.size(); ++i)
            {
                m *= nums[i];
            }
            
            for (int i = 0; i < nums.size(); ++i)
            {
                ans[i] = m / nums[i];
            }
            
            return ans;
        }
    }
};