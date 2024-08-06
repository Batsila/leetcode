public class Solution
{
    public int MinimumPushes(string word)
    {
        return word.GroupBy(x => x)
                   .Select(x => (x.Key, x.Count()))
                   .OrderByDescending(x => x.Item2)
                   .Select((x, i) => (i / 8 + 1) * x.Item2)
                   .Sum();
    }
}