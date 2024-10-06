public class Solution
{
    public bool CanFinish(int numCourses, int[][] prerequisites)
    {
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
                if (!TrySort(course, graph, states))
                {
                    return false;
                }
            }
        }

        return true;
    }

    private bool TrySort(
        int v,
        List<List<int>> graph,
        int[] states)
    {
        if (states[v] == 0)
        {
            states[v] = 1;

            foreach (var u in graph[v])
            {
                if (!TrySort(u, graph, states))
                {
                    return false;
                }
            }

            states[v] = 2;
        }
        else if (states[v] == 1)
        {
            return false;
        }
        
        return true;
    }
}