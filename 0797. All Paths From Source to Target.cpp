class Solution
{
    vector<vector<int>> ans;
    vector<vector<int>> g;
    vector<bool> used;
    vector<int> path;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        g = graph;
        used = vector<bool>(g.size());
        dfs(0);
        
        return ans;
    }
    
    void dfs(int v)
    {
        used[v] = true;
        path.push_back(v);
        
        if (v == g.size() - 1)
        {
            vector<int> t = vector<int>(path);
            ans.push_back(t);
        }
        else
        {
            for (int u : g[v])
            {
                if (not used[u])
                {
                    dfs(u);
                }
            }
        }
        
        path.pop_back();
        used[v] = false;
    }
};