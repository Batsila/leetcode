class Solution
{
public:
    int minimumDeviation(vector<int>& nums)
    {
        set<int> s;
        
        for (int num : nums)
        {
            if (num % 2)
            {
                s.insert(num * 2);
            }
            else
            {
                s.insert(num);
            }
        }
        
        int ans = *s.rbegin() - *s.begin();
        
        while (*s.rbegin() % 2 == 0)
        {
            int c = *s.rbegin();
            
            s.erase(c);
            s.insert(c / 2);
            
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        
        return ans;
    }
};