class Solution
{
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        sort(changed.begin(), changed.end());
        vector<bool> used(changed.size());
        map<int, set<int>> m;
        
        for (int i = 0; i < changed.size(); ++i)
        {
            m[changed[i]].insert(i);
        }
        
        vector<int> ans;
        
        for (int i = 0; i < changed.size(); ++i)
        {
            if (not used[i])
            {
                if (m.find(changed[i] * 2) != m.end())
                {
                    used[i] = true;
                    ans.push_back(changed[i]);
                    m[changed[i]].erase(i);
                    
                    if (m[changed[i] * 2].size() > 0)
                    {
                        int di = *(m[changed[i] * 2].begin());
                        m[changed[i] * 2].erase(di);
                        used[di] = true;
                    }
                    else
                    {
                        return {};
                    }
                }
                else
                {
                    return {};
                }
            }
        }
        
        return ans;
    }
};