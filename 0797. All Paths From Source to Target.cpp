class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<bool> visited = vector<bool>(graph.size());
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(0, graph, visited, path, result);

        return result;
    }
    
    void dfs(
        int v,
        vector<vector<int>>& graph,
        vector<bool>& visited,
        vector<int>& path,
        vector<vector<int>>& result)
    {
        visited[v] = true;
        path.push_back(v);
        
        if (v == graph.size() - 1)
        {
            result.push_back(path);
        }
        else
        {
            for (int u : graph[v])
            {
                if (not visited[u])
                {
                    dfs(u, graph, visited, path, result);
                }
            }
        }
        
        path.pop_back();
        visited[v] = false;
    }
};