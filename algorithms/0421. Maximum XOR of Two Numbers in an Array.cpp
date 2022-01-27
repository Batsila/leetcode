class Solution
{
public:
    int findMaximumXOR(vector<int>& nums)
    {
        int ans = 0;
        int mask = 0;
        
        for (int i = 31; i >= 0; --i)
        {
            mask |= (1 << i);
            unordered_set<int> s;
            
            for (int num : nums) 
            {
                s.insert(num & mask);
            }
            
            int t = ans | (1 << i);
            
            for (int prefix : s)
            {
                if (s.count(t ^ prefix))
                {
                    ans = t;
                    break;
                }
            }
        }
        
        return ans;
    }
};