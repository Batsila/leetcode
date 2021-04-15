class Solution 
{
    map<char, int> m =
    {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };
    
public:
    int romanToInt(string s) 
    {
        int c = 0;
        
        int ans = 0;
        
        for (int i = s.size() - 1; i >= 0; --i)
        {
            int n = m.find(s[i])->second;
            
            if (n >= c)
            {
                c = n;
                ans += n;
            }
            else
            {
                ans -= n;
            }
        }
        
        return ans;
    }
};