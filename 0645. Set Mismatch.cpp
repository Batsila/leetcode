class Solution
{
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        vector<int> counts(nums.size(), 0);
        
        for (int num : nums)
        {
            ++counts[num - 1];
        }
        
        vector<int> ans(2);
        
        for (int i = 0; i < counts.size(); ++i)
        {
            if (counts[i] == 2)
            {
                ans[0] = i + 1;
            }
            
            if (counts[i] == 0)
            {
                ans[1] = i + 1;
            }
        }
        
        return ans;
    }
};