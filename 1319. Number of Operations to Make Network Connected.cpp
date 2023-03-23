class Solution 
{   
    vector<vector<int>> g;
    bool used[100000];
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {   
        g = vector<vector<int>>(n, vector<int>());
        
        for (auto e : connections)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        int c = 0;

        for (int i = 0; i < n; ++i)
        {
            if (not used[i])
            {
                dfs(i);
                ++c;
            }
        }
        
        if (connections.size() < n - 1)
        {
            return -1;
        }
        else
        {
            return c - 1;
        }
    }
    
    void dfs(int v)
    {
        used[v] = true;
        
        for (int u : g[v])
        {
            if (not used[u])
            {
                dfs(u);
            }
        }
    }
};