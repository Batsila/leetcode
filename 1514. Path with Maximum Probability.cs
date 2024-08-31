public class Solution
{
    public double MaxProbability(
        int n,
        int[][] edges,
        double[] succProb,
        int start_node,
        int end_node)
    {
        var graph = Enumerable.Range(0, n).Select(x => new List<(int node, double prob)>()).ToList();

        for (int i = 0; i < edges.Length; ++i)
        {
            graph[edges[i][0]].Add((edges[i][1], succProb[i]));
            graph[edges[i][1]].Add((edges[i][0], succProb[i]));
        }

        var probabilities = new double[n];
        probabilities[start_node] = 1;

        var heap = new PriorityQueue<(int node, double prob), double>();
        heap.Enqueue((start_node, 1), -1);

        while (heap.Count > 0)
        {
            var current = heap.Dequeue();

            if (current.node != end_node)
            {
                foreach (var neighbor in graph[current.node])
                {
                    if (current.prob * neighbor.prob > probabilities[neighbor.node])
                    {
                        probabilities[neighbor.node] = current.prob * neighbor.prob;
                        heap.Enqueue((neighbor.node, probabilities[neighbor.node]), -probabilities[neighbor.node]);
                    }
                }
            }
            else
            {
                return current.prob;
            }
        }

        return 0;
    }
}