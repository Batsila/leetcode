class Solution
{
public:
    int maxPower(string s)
    {
        int ans = 1;
        int c = 1;
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                ++c;
            }
            else
            {
                ans = max(ans, c);
                c = 1;
            }
        }
        
        ans = max(ans, c);
        
        return ans;
    }
};