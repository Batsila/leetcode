class Solution
{
    int N;
    vector<vector<int>> g;
    vector<int> ans;
    vector<int> c;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        N = n;
        g = vector<vector<int>>(n, vector<int>());
        
        for (auto edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        ans = vector<int>(n, 0);
        c = vector<int>(n, 1);
        
        dfs(0, -1);
        dfs2(0, -1);
        
        return ans;
    }
    
    void dfs(int v, int p)
    {
        for (int u : g[v])
        {
            if (u != p)
            {
                dfs(u, v);
                c[v] += c[u];
                ans[v] += ans[u] + c[u];
            }
        }
    }
    
    void dfs2(int v, int p)
    {
        for (int u : g[v])
        {
            if (u != p)
            {
                ans[u] = ans[v] - 2 * c[u] + N;
                dfs2(u, v);
            }
        }
    }
};