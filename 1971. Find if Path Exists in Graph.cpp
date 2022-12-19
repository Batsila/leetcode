class Solution
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> used(n);

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(source, graph, used);

        return used[destination];
    }

    void dfs(int v, vector<vector<int>>& graph, vector<bool>& used)
    {
        used[v] = true;

        for (int u : graph[v])
        {
            if (!used[u])
            {
                dfs(u, graph, used);
            }
        }
    }
};