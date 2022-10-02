class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        unordered_map<string, int> m;
        vector<vector<int>> ans;
        
        for (int i = 0; i < words.size(); ++i)
        {
            string rs = reverse_str(words[i]);
            m[rs] = i;
        }
        
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j <= words[i].size(); ++j)
            {
                string b = words[i].substr(0, j);
                string e = words[i].substr(j);
                
                if (m.count(b) and is_palindrome(e) and m[b] != i)
                {
                    ans.push_back({ i, m[b] });
                }
                    
                if (b.size() > 0 and m.count(e) and is_palindrome(b) and m[e] != i)
                {
                    ans.push_back({ m[e], i });
                }
            }
        }
        
        return ans;
    }
    
    string reverse_str(string s)
    {
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        return rs;
    }
    
    bool is_palindrome(string s)
    {
        string rs = reverse_str(s);
    
        return rs == s;
    }
};