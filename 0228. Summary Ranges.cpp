class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return { };
        }
        
        vector<string> ans;
        
        int a = nums[0];
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == nums.size() - 1 or nums[i] + 1 != nums[i + 1])
            {
                if (a == nums[i])
                {
                    ans.push_back(to_string(a));
                }
                else
                {
                    ans.push_back(to_string(a) + "->" + to_string(nums[i]));
                }
                
                if (i != nums.size() - 1)
                {
                    a = nums[i + 1];
                }
            }
        }
        
        return ans;
    }
};