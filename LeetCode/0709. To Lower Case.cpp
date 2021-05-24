class Solution
{
public:
    string toLowerCase(string s)
    {
        int d = 'a' - 'A';
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= 'A' and s[i] <= 'Z')
            {
                s[i] += d;
            }
        }
        
        return s;
    }
};