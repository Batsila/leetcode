class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int ans = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            ans += t[i] - s[i];
        }
        
        ans += t[t.size() - 1];
        
        return ans;
    }
};