class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() == 0 or t.size() == 0)
        {
            return "";
        }
        
        map<char, int> tm;
        
        for (char c : t)
        {
            ++tm[c];
        }
        
        map<char, int> sm;
        int l = 0;
        int r = 0;
        int cs = 0;
        string ans = "";
        bool isAns = false;
        
        while (r < s.size())
        {
            ++sm[s[r]];
            
            if (tm.find(s[r]) != tm.end() and tm[s[r]] == sm[s[r]])
            {
                ++cs;
            }
            
            while (l <= r and cs == tm.size())
            {
                if (not isAns or r - l + 1 < ans.size())
                {
                    isAns = true;
                    ans = s.substr(l, r - l + 1);
                }
                
                --sm[s[l]];
                
                if (tm.find(s[l]) != tm.end() and tm[s[l]] > sm[s[l]])
                {
                    --cs;
                }
                
                ++l;
            }
            
            ++r;
        }
        
        return ans;
    }
    
};