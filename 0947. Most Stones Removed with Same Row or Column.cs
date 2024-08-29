public class Solution
{
    public int RemoveStones(int[][] stones)
    {
        var graph = Enumerable.Range(0, stones.Length).Select(x => new List<int>()).ToList();

        for (int i = 0; i < stones.Length; ++i)
        {
            for (int j = i + 1; j < stones.Length; ++j)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    graph[i].Add(j);
                    graph[j].Add(i);
                }
            }
        }

        var isVisited = new bool[stones.Length];
        var componentsCount = 0;

        for (int i = 0; i < stones.Length; ++i)
        {
            if (!isVisited[i])
            {
                Dfs(i, graph, isVisited);
                ++componentsCount;
            }
        }

        return stones.Length - componentsCount;
    }

    private void Dfs(
        int stone,
        List<List<int>> graph,
        bool[] isVisited)
    {
        isVisited[stone] = true;

        foreach (var node in graph[stone])
        {
            if (!isVisited[node])
            {
                Dfs(node, graph, isVisited);
            }
        }
    }
}