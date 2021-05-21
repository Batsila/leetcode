class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
     {
        vector<string> ans;
        
        for (string word : words)
        {
            if (check(word, pattern))
            {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
    
    bool check(string a, string b)
    {
        unordered_map<char, char> um_a;
        unordered_map<char, char> um_b;
        
        for (int i = 0; i < a.size(); ++i)
        {
            if (um_a.find(a[i]) == um_a.end())
            {
                um_a[a[i]] = b[i];
            }
            
            if (um_b.find(b[i]) == um_b.end())
            {
                um_b[b[i]] = a[i];
            }
            
            if (um_a[a[i]] != b[i] or um_b[b[i]] != a[i])
            {
                return false;
            }
        }
        
        return true;
    }
};