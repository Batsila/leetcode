class Solution
{
public:
    int maxOperations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.size() - 1;
        
        int ans = 0;
        
        while (r > l)
        {
            if (nums[r] + nums[l] < k)
            {
                ++l;
            }
            else if (nums[r] + nums[l] > k)
            {
                --r;
            }
            else
            {
                ++ans;
                ++l;
                --r;
            }
        }
        
        return ans;
    }
};