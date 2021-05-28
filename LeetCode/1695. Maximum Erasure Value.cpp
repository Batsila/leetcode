class Solution
{
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        unordered_map<int, int> um;
        
        int l = 0;
        int sum = 0;
        int ans = 0;
        
        for (int r = 0; r < nums.size(); ++r)
        {
            if (um.find(nums[r]) != um.end())
            {
                while (l <= um[nums[r]])
                {
                    um.erase(nums[l]);
                    sum -= nums[l];
                    ++l;
                }
            }
            
            um[nums[r]] = r;
            sum += nums[r];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};