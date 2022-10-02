class Solution
{
public:
    int minStartValue(vector<int>& nums)
    {
        int p = nums[0];
        int as = nums[0];
        int ans = min(0, nums[0]);
        
        for (int i = 1; i < nums.size(); ++i)
        {
            as += nums[i];
            ans = min(ans, as);
        }
        
        return 1 - ans;
    }
};