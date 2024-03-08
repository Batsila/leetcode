public class Solution
{
    public int MaxFrequencyElements(int[] nums)
    {
        var frequencies = nums.GroupBy(x => x).Select(g => new { Value = g.Key, Count = g.Count() });
        var maxFrequency = frequencies.Max(f => f.Count);

        return frequencies.Where(x => x.Count == maxFrequency).Count() * maxFrequency;
    }
}