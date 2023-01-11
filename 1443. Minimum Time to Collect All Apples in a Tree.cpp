class Solution 
{
    bool used[123456];
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>> g;
        
        for (int i = 0; i < n; ++i)
        {
            vector<int> t;
            g.push_back(t);
        }
        
        for (auto edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0, g, hasApple);
    }
    
    int dfs(int v, vector<vector<int>>& g, vector<bool>& hasApple)
    {
        used[v] = true;
        int sum = 0;
        
        for (int u : g[v])
        {
            if (not used[u])
            {
                sum += dfs(u, g, hasApple);
            }
        }
        
        if ((sum > 0 or hasApple[v]) and v != 0)
        {
            sum += 2;
        }
        
        return sum;
    }
};