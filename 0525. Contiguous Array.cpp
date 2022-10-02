class Solution
{
public:
    int findMaxLength(vector<int>& nums)
    {
        map<int, int> m;
        m[0] = -1;
        
        int ans = 0;
        int c = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            c += nums[i] ? 1 : -1;
            
            if (m.find(c) != m.end())
            {
                ans = max(ans, i - m[c]);
            }
            else
            {
                m[c] = i;
            }
        }
        
        return ans;
    }
};