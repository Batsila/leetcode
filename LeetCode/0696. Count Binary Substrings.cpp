class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        vector<int> g;
        g.push_back(1);
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                g[g.size() - 1] += 1;
            }
            else
            {
                g.push_back(1);
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i < g.size(); ++i)
        {
            ans += min(g[i - 1], g[i]);
        }
        
        return ans;
    }
};