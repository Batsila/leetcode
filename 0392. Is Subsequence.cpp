class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int ind = 0;
        
        for (char c : t)
        {
            if (ind < s.size() and c == s[ind])
            {
                ++ind;
            }
        }
        
        return ind == s.size();
    }
};