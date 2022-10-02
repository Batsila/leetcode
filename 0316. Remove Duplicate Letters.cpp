class Solution
{
    int count[26];
    bool visited[26];
public:
    string removeDuplicateLetters(string s)
    {
        for (char c : s)
        {
            ++count[c - 'a'];
        }
        
        string ans = "";
        
        for (char c : s)
        {
            --count[c - 'a'];
            
            if (not visited[c - 'a'])
            {
                while (ans.size() > 0
                       and ans.back() > c
                       and count[ans.back() - 'a'])
                {
                    visited[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                
                visited[c - 'a'] = true;
                ans += c;
            }
        }
        
        return ans;
    }
};