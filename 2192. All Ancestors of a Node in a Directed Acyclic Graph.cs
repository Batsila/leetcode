public class Solution
{
    public IList<IList<int>> GetAncestors(int n, int[][] edges)
    {
        var graph = Enumerable.Range(0, n).Select(x => new List<int>()).ToList();

        foreach (var edge in edges)
        {
            graph[edge[0]].Add(edge[1]);
        }

        var ancestors = Enumerable.Range(0, n).Select(x => (IList<int>)new List<int>()).ToList();

        for (int i = 0; i < n; ++i)
        {
            FindAncestors(i, i, graph, ancestors);
        }

        return ancestors;
    }

    private void FindAncestors(
        int ancestorNode,
        int currentNode,
        List<List<int>> graph,
        IList<IList<int>> ancestors)
    {
        foreach (var node in graph[currentNode])
        {
            if (ancestors[node].Count == 0
                || ancestors[node][^1] != ancestorNode) 
            {
                ancestors[node].Add(ancestorNode);
                FindAncestors(ancestorNode, node, graph, ancestors);
            }
        }
    }
}