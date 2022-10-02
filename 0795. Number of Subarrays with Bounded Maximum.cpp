class Solution
{
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right)
    {
        int ans = 0;
        
        int ok = 0;
        int not_ok = 0;
        
        for (auto num : nums)
        {
            if (num > right)
            {
                ok = 0;
            }
            else
            {
                ++ok;
                ans += ok;
            }
            
            if (num >= left)
            {
                not_ok = 0;
            }
            else
            {
                ++not_ok;
                ans -= not_ok;
            }
        }
        
        return ans;
    }
};