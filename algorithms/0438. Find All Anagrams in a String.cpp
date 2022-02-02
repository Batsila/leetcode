class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
        {
            return { };
        }
        
        vector<int> pl(26, 0);
        vector<int> sl(26, 0);
        
        for (int i = 0; i < p.size(); ++i)
        {
            ++pl[p[i] - 'a'];
            ++sl[s[i] - 'a'];
        }
        
        vector<int> ans;
        
        if (pl == sl)
        {
            ans.push_back(0);
        }
        
        for (int i = p.size(); i < s.size(); ++i)
        {
            --sl[s[i - p.size()] - 'a'];
            ++sl[s[i] - 'a'];
            
            if (pl == sl)
            {
                ans.push_back(i - p.size() + 1);
            }
        }
        
        return ans;
    }
};