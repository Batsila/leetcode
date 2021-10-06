class Solution
{
    int s[50001];
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        for (int num : nums)
        {
            ++s[num];
        }
        
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (s[i + 1] == 2)
            {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};