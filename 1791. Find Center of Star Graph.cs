public class Solution
{
    public int FindCenter(int[][] edges)
    {
        var adjacentNodes = new int[edges.Length + 1];

        foreach (var edge in edges)
        {
            ++adjacentNodes[edge[0] - 1];
            ++adjacentNodes[edge[1] - 1];
        }

        for (int i = 0; i < adjacentNodes.Length; ++i)
        {
            if (adjacentNodes[i] > 1)
            {
                return i + 1;
            }
        }

        return -1;
    }
}