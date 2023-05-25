public class Solution
{
    public bool ValidPath(int n, int[][] edges, int source, int destination)
    {
        var graph = new List<IList<int>>();

        for(int i = 0; i < n; ++i)
        {
            graph.Add(new List<int>());
        }

        foreach (var edge in edges)
        {
            graph[edge[0]].Add(edge[1]);
            graph[edge[1]].Add(edge[0]);
        }

        var isUsed = new HashSet<int>();

        Dfs(source, graph, isUsed);

        return isUsed.Contains(destination);
    }

    private void Dfs(int v, IList<IList<int>> graph, HashSet<int> isUsed)
    {
        isUsed.Add(v);

        foreach (var u in graph[v])
        {
            if (!isUsed.Contains(u))
            {
                Dfs(u, graph, isUsed);
            }
        }
    }
}