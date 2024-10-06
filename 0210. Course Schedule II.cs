public class Solution
{
    public int[] FindOrder(int numCourses, int[][] prerequisites)
    {
        var result = new List<int>();
        var indegrees = new int[numCourses];
        var graph = Enumerable.Range(0, numCourses).Select(x => new List<int>()).ToList();

        foreach (var prerequisite in prerequisites)
        {
            graph[prerequisite[1]].Add(prerequisite[0]);
            ++indegrees[prerequisite[0]];
        }

        for (int i = 0; i < indegrees.Length; ++i)
        {
            if (indegrees[i] == 0)
            {
                result.Add(i);
            }
        }

        for (int i = 0; i < result.Count; ++i)
        {
            foreach (var v in graph[result[i]])
            {
                --indegrees[v];

                if (indegrees[v] == 0)
                {
                    result.Add(v);
                }
            }
        }

        return result.Count == numCourses ? result.ToArray() : [];
    }
}