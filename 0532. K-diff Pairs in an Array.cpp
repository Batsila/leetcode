class Solution
{
public:
    int findPairs(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;
        
        for (int num : nums)
        {
            ++m[num];
        }
        
        int ans = 0;
        
        for (auto f : m)
        {
            if (k == 0)
            {
                if (f.second > 1)
                {
                    ++ans;
                }
            }
            else
            {
                if (m.find(f.first + k) != m.end())
                {
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};