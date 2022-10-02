class Solution 
{
public:
    vector<vector<int>> g;
    vector<int> c;
    vector<int> ans;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        c = vector<int>(numCourses);
        g = vector<vector<int>>(numCourses, vector<int>());
        
        for (vector<int> prerequisite : prerequisites)
        {
            g[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        for (int i = 0; i < numCourses; ++i)
        {
            if (!c[i])
            {
                if (!dfs(i))
                {
                    return {};
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    bool dfs(int v)
    {
        c[v] = 1;
        
        for (int u : g[v])
        {
            if (!c[u])
            {
                if (!dfs(u))
                {
                    return false;
                }
            }
            else if (c[u] == 1)
            {
                return false;
            }
        }
        
        c[v] = 2;
        
        ans.push_back(v);
        
        return true;
    }
};