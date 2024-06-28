public class Solution
{
    public long MaximumImportance(int n, int[][] roads)
    {
        var adjacencyCountPerCity = new int[n];

        foreach (var road in roads)
        {
            ++adjacencyCountPerCity[road[0]];
            ++adjacencyCountPerCity[road[1]];
        }

        Array.Sort(adjacencyCountPerCity);

        return adjacencyCountPerCity.Select((adjacency, index) => (long)adjacency * (index + 1)).Sum();
    }
}