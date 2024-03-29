class Solution 
{
public:
    vector<vector<int>> g;
    vector<int> c;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        c = vector<int>(numCourses, 0);
        g = vector<vector<int>>(numCourses, vector<int>());
        
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for (int i = 0; i < numCourses; ++i)
        {
            if (!c[i])
            {
                if (!dfs(i))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(int v)
    {
        c[v] = 1;
        
        for (int i = 0; i < g[v].size(); ++i)
        {
            int u = g[v][i];

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
        
        return true;
    }
};