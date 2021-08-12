class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> m;
        
        for (string str : strs)
        {
            string t = str;
            sort(t.begin(), t.end());
            
            if (m.find(t) != m.end())
            {
                m[t].push_back(str);
            }
            else
            {
                m[t] = { str };
            }
        }
        
        vector<vector<string>> ans;
        
        for (auto p : m)
        {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};