class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> um;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            um.insert(make_pair(nums[i], i));
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = um.find(target - nums[i]);
            
            if (it != um.end() && it->second != i)
            {
                return vector<int> { i, it->second }; 
            }
        }
        
        throw exception();
    }
};