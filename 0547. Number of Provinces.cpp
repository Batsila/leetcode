class Solution
{
    vector<bool> used;
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        used = vector<bool>(isConnected.size(), false);
        int ans = 0;

        for (int v = 0; v < isConnected.size(); ++v)
        {
            if (not used[v])
            {
                ++ans;
                dfs(v, isConnected);
            }
        }

        return ans;
    }

    void dfs(int v, vector<vector<int>>& graph)
    {
        used[v] = true;

        for (int u = 0; u < graph[v].size(); ++u)
        {
            if (graph[v][u] == 1 and not used[u])
            {
                dfs(u, graph);
            }
        }
    }
};