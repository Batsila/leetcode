class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1)
        {
            return s;
        }
        
        vector<vector<char>> m;
        
        for (int i = 0; i < numRows; ++i)
        {
            vector<char> t;
            m.push_back(t);
        }
        
        bool d = true;
        int i = 0;
        
        for (char c : s)
        {
            m[i].push_back(c);
            
            if (d)
            {
                ++i;
            }
            else
            {
                --i;
            }
            
            if (d && i == numRows - 1)
            {
                d = false;
            }
            else if (!d && i == 0)
            {
                d = true;
            }
        }
        
        string ans = "";
        
        for (auto v : m)
        {
            for (char c : v)
            {
                ans += c;
            }
        }
        
        return ans;
    }
};