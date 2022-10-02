class Solution
{
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        help({}, nums);
        
        return ans;
    }
    
    void help(vector<int> prefix, vector<int> nums)
    {
        ans.push_back(prefix);
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (prefix.size() == 0 or nums[i] > prefix[prefix.size() - 1])
            {
                vector<int> tp(prefix);
                tp.push_back(nums[i]);
            
                vector<int> tn(nums);
                tn.erase(tn.begin() + i);
            
                help(tp, tn);
            }
        }
    }
};