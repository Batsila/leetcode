class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        if (nums.size() < 3)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            while (nums[i] == 0 and i < nums.size())
            {
                ++i;
            }
            
            for (int j = i + 1, k = i + 2; j < nums.size() - 1; ++j)
            {
                while (k < nums.size() and nums[i] + nums[j] > nums[k])
                {
                    ++k;
                }
                
                ans += k - j - 1;
            }
        }
        
        return ans;
    }
};