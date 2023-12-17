class Solution
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> graph = buildGraph(n, edges);

        dfsRecursion(source, graph, visited);

        return visited[destination];
    }

    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n, vector<int>());

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (not q.empty())
        {
            int v = q.front();
            q.pop();

            for (int u : graph[v])
            {
                if (not visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }

    void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited)
    {
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (not s.empty())
        {
            int v = s.top();
            s.pop();

            for (int u : graph[v])
            {
                if (not visited[u])
                {
                    visited[u] = true;
                    s.push(u);
                }
            }
        }
    }

    void dfsRecursion(int v, vector<vector<int>>& graph, vector<bool>& visited)
    {
        visited[v] = true;

        for (int u : graph[v])
        {
            if (not visited[u])
            {
                dfsRecursion(u, graph, visited);
            }
        }
    }
};