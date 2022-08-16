class Solution
{
    map<char, int> m;
public:
    int firstUniqChar(string s)
    {
        for (char c : s)
        {
            ++m[c];
        }
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (m[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};