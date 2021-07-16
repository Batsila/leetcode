class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 and nums[i] == nums[i-1])
            {
                continue;
            }
            
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j != i + 1 and nums[j] == nums[j-1])
                {
                    continue;
                }
                
                auto it = m.find(-nums[i] - nums[j]);
                
                if (it != m.end() and it->second > j)
                {
                    ans.push_back({ nums[i], nums[j], -nums[i] - nums[j] });
                }
            }
        }
        
        return ans;
    }
};