class Solution
{
    vector<bool> used;
    vector<vector<int>> graph;
public:
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        used = vector<bool>(n);
        graph = vector<vector<int>>(n, vector<int>());

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long ans = 0;
        long long nodesLeft = n;

        for (int v = 0; v < n; ++v)
        {
            if (not used[v])
            {
                long long count = dfs(v);
                nodesLeft -= count;
                ans += count * nodesLeft;
            }
        }

        return ans;
    }

    long long dfs(int v)
    {
        used[v] = true;
        long long count = 1;

        for (int u : graph[v])
        {
            if (not used[u])
            {
                count += dfs(u);
            }
        }
        
        return count;
    }
};