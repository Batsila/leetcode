class Solution
{
    set<long> s;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
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
            vector<int> tp(prefix);
            tp.push_back(nums[i]);
            
            sort(tp.begin(), tp.end());
            long ch = 0;
            
            for (int e : tp)
            {
                ch = ch * 10 + (e + 10);
            }
            
            if (s.find(ch) == s.end())
            {
                s.insert(ch);
            
                vector<int> tn(nums);
                tn.erase(tn.begin() + i);
            
                help(tp, tn);
            }
        }
    }
};