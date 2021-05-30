class Solution
{
    vector<string> ans;
public:
    vector<string> ambiguousCoordinates(string s)
    {
        s = s.substr(1, s.size() - 2);
        for (int i = 1; i < s.size(); ++i)
        {
            vector<string> a = help(s.substr(0, i));
            vector<string> b = help(s.substr(i));
            
            for (int j = 0; j < a.size(); ++j)
            {
                for (int k = 0; k < b.size(); ++k)
                {
                    string t = "(" + a[j] + ", " + b[k] + ")";
                    ans.push_back(t);
                }
            }
        }
        
        return ans;
    }
    
    vector<string> help(string s) 
    {
        vector<string> res;
        
        if (s.size() == 1)
        {
            return { s };
        }
        
        if (s[0] != '0')
        {
            res.push_back(s);
        }
            
        
        if (s[0] == '0') 
        {
            if (s.back() == '0')
            {
                return {};
            }
            
            return { "0." + s.substr(1) };
        }
        
        for (int i = 1; i < s.size(); ++i) 
        {
            if (s.substr(i).back() != '0')
            {
                res.push_back(s.substr(0, i) + "." + s.substr(i));
            }
        }
        
        return res;
    }
};