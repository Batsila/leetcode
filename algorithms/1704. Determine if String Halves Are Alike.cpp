class Solution 
{
    set<char> l = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    
public:
    bool halvesAreAlike(string s) 
    {
        int a = 0;
        int b = 0;
        
        for (int i = 0; i < s.size() / 2; ++i)
        {  
            if (l.find(s[i]) != l.end())
            {
                ++a;
            }
            
            if (l.find(s[s.size() / 2 + i]) != l.end())
            {
                ++b;
            }
        }
        
        return a == b;;
    }
};