class Solution
{
public:
    int findLUSlength(vector<string>& strs)
    {
        unordered_map<string, int> m;
        
        for (string str : strs)
        {
            for (int i = 0; i < pow(2, str.size()); ++i)
            {
                string sub_str;
                
                for (int j = 0; j < str.size(); ++j) 
                {
                    if ((i >> j) & 1)
                    {
                        sub_str += str[j];
                    }
                }
                
                ++m[sub_str];
            }
        }
        
        int ans = -1;
        
        for (auto p : m)
        {
            if (p.second == 1)
            {
                ans = max(ans, (int)p.first.size());
            }
        }
        
        return ans;
    }
};