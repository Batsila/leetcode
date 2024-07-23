public class Solution
{
    public int[] FrequencySort(int[] nums)
    {
        var frequencies = nums
            .GroupBy(x => x)
            .Select(x => (x.Key, x.Count()))
            .OrderBy(x => x.Item2)
            .ThenByDescending(x => x.Item1);
        
        var result = new List<int>(nums.Length);

        foreach (var item in frequencies)
        {
            result.AddRange(Enumerable.Range(0, item.Item2).Select(x => item.Item1));
        }

        return result.ToArray();
    }
}