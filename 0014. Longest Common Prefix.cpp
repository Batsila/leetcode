class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        
        string p = strs[0];
        
        for (int i = 1; i < strs.size(); ++i)
        {
            string np = "";
            
            for (int j = 0; j < p.size() and j < strs[i].size(); ++j)
            {
                if (p[j] == strs[i][j])
                {
                    np += p[j];
                }
                else
                {
                    break;
                }
            }
            
            p = np;
        }
        
        return p;
    }
};