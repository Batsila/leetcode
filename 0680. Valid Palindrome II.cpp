class Solution
{
public:
    bool validPalindrome(string s, bool c = true)
    {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r)
        {
            if (s[l] != s[r])
            {
                if (c)
                {
                    string s1 = s;
                    string s2 = s;
                    
                    s1.erase(l, 1);
                    s2.erase(r, 1);
                    
                    return validPalindrome(s1, false) or validPalindrome(s2, false);
                }
                else
                {
                    return false;
                }
            }
            
            ++l;
            --r;
        }
        
        return true;
    }
};