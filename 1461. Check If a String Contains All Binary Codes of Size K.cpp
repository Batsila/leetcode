class Solution
{
    unordered_set<string> unique;
public:
    bool hasAllCodes(string s, int k)
    {
        if (s.size() < k)
        {
            return false;
        }
        
        int n = 1 << k;
        
        for (int i = 0; i <= s.size() - k; ++i)
        {
            unique.insert(s.substr(i, k));
        }
        
        return unique.size() == n;
    }
};