class Solution
{
public:    
    bool backspaceCompare(string s, string t)
    {
        return process(s) == process(t);
    }
    
    string process(string str)
    {
        stack<char> s;
        
        for (char c : str)
        {
            if (c == '#')
            {
                if (not s.empty())
                {
                    s.pop();
                }
            }
            else
            {
                s.push(c);
            }
        }
        
        string res = "";
        
        while (not s.empty())
        {
            res += s.top();
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};