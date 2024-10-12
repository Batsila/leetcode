public class Solution
{
    public int MinGroups(int[][] intervals)
    {
        var events = new List<(int, int)>();

        foreach (var interval in intervals)
        {
            events.Add((interval[0], 1));
            events.Add((interval[1] + 1, -1));
        }

        var result = 0;
        var intersections = 0;

        foreach (var currentEvent in events.OrderBy(x => x.Item1).ThenBy(x => x.Item2))
        {
            intersections += currentEvent.Item2;
            result = int.Max(result, intersections);
        }

        return result;
    }
}