public class Solution
{
    public bool CanVisitAllRooms(IList<IList<int>> rooms)
    {
        var isUsed = new HashSet<int>();
        Dfs(0, rooms, isUsed);

        return isUsed.Count == rooms.Count();
    }

    public void Dfs(int v, IList<IList<int>> graph, HashSet<int> isUsed)
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