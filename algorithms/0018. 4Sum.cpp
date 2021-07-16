class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = i;
        }
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 and nums[i] == nums[i - 1])
            {
                continue;
            }
            
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j != i + 1 and nums[j] == nums[j - 1])
                {
                    continue;
                }
                
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (k != j + 1 and nums[k] == nums[k - 1])
                    {
                        continue;
                    }
                    
                    auto it = m.find(target - nums[i] - nums[j] - nums[k]);
                
                    if (it != m.end() and it->second > k)
                    {
                        ans.push_back({ nums[i], nums[j], nums[k], target - nums[i] - nums[j] - nums[k] });
                    }
                }
            }
        }
        
        return ans;
    }
};