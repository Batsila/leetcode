public class Solution
{
    public int[] FindOrder(int numCourses, int[][] prerequisites)
    {
        var order = new List<int>();
        var states = new int[numCourses]; // 0 - not visited, 1 - in, 2 - out
        var graph = Enumerable.Range(0, numCourses).Select(x => new List<int>()).ToList();

        foreach (var prerequisite in prerequisites)
        {
            graph[prerequisite[0]].Add(prerequisite[1]);
        }

        for (int course = 0; course < numCourses; ++course)
        {
            if (states[course] == 0)
            {
                if (!TrySort(course, graph, states, order))
                {
                    return [];
                }
            }
        }

        return order.ToArray();
    }

    private bool TrySort(
        int v,
        List<List<int>> graph,
        int[] states,
        List<int> order)
    {
        if (states[v] == 0)
        {
            states[v] = 1;

            foreach (var u in graph[v])
            {
                if (!TrySort(u, graph, states, order))
                {
                    return false;
                }
            }

            states[v] = 2;
            order.Add(v);
        }
        else if (states[v] == 1)
        {
            return false;
        }
        
        return true;
    }
}