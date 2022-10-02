class Solution
{
public:
    int removePalindromeSub(string s)
    {
        return isPalindrome(s) ? 1 : 2;
    }
    
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        
        while (r >= l)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            
            --r;
            ++l;
        }
        
        return true;
    }
};