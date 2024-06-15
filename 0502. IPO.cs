public class Solution
{
    public int FindMaximizedCapital(int k, int w, int[] profits, int[] capital)
    {
        var projects = capital.Zip(profits, (x, y) => (x, y)).OrderBy(x => x.Item1).ToArray();
        var heap = new PriorityQueue<int, int>();
        var projectIndex = AddAvailableProjects(heap, projects, 0, w);

        while (k > 0)
        {
            if (heap.Count > 0)
            {
                w += heap.Dequeue();
                projectIndex = AddAvailableProjects(heap, projects, projectIndex, w);
                --k;
            }
            else
            {
                break;
            }
        }

        return w;
    }

    private int AddAvailableProjects(
        PriorityQueue<int, int> heap,
        (int, int)[] projects,
        int projectIndex,
        int w)
    {
        while (projectIndex < projects.Length)
        {
            if (projects[projectIndex].Item1 <= w)
            {
                heap.Enqueue(projects[projectIndex].Item2, -projects[projectIndex].Item2);
                ++projectIndex;
            }
            else
            {
                break;
            }
        }

        return projectIndex;
    }
}