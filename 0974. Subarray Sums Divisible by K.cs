public class Solution
{
    public int SubarraysDivByK(int[] nums, int k)
    {
        var modFrequencies = new Dictionary<int, int>
        {
            { 0, 1 }
        };
        var prefixMod = 0;
        var result = 0;

        foreach (var num in nums)
        {
            prefixMod += num % k + k;
            prefixMod %= k;

            if (modFrequencies.TryGetValue(prefixMod, out var count))
            {
                result += count;
                ++modFrequencies[prefixMod];
            }
            else
            {
                modFrequencies.Add(prefixMod, 1);
            }
        }

        return result;
    }
}