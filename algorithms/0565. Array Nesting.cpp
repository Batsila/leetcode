class Solution
{
public:
    int arrayNesting(vector<int>& nums)
    {
        vector<bool> v(nums.size(), false);
        int ans = 0;
        
        for (int k = 0; k < nums.size(); ++k)
        {
            if (not v[k])
            {
                int ind = k;
                int c = 0;
                
                do
                {
                    ++c;
                    v[ind] = true;
                    ind = nums[ind];
                }
                while (ind != k);
                
                ans = max(ans, c);
            }
        }
        
        return ans;
    }
};