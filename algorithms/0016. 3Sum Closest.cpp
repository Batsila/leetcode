class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        
        long ans = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (abs(ans - target) > abs(sum - target))
                {
                    ans = sum;
                }
                
                if (sum < target)
                {
                    ++l;
                }
                else
                {
                    --r;
                }  
            }
        }
        
        return ans;
    }
};