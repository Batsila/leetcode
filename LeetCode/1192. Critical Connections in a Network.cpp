class Solution 
{
    vector<vector<int>> g;
    int t[123456];
    int f[123456];
    bool used[123456];
    int c;
    vector<vector<int>> ans;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {   
        for (int i = 0; i < n; ++i)
        {
            vector<int> t;
            
            g.push_back(t);
        }
        
        for (auto r : connections)
        {
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        
        dfs(0, -1);    
        
        return ans;
    }
    
    void dfs(int v, int p)
    {
        used[v] = true;
        t[v] = c++;
        f[v] = t[v];
        
        for (auto u : g[v])
        {
            if (u != p)
            {
                if (used[u])
                {
                    f[v] = min(f[v], t[u]);
                }
                else
                {
                    dfs(u, v); 
                    f[v] = min(f[v], f[u]);
                    
                    if (f[u] > t[v])
                    {
                        vector r = { u, v };
                        
                        ans.push_back(r);
                    }
                }
            }
            
        }
    }             
};