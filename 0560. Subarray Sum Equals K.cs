public class Solution
{
    public int SubarraySum(int[] nums, int k)
    {
        var result = 0;
        var sumFrequencies = new Dictionary<int, int>
        {
            { 0, 1 }
        };
        var sum = 0;

        foreach (var num in nums)
        {
            sum += num;

            if (sumFrequencies.TryGetValue(sum - k, out var frequency))
            {
                result += frequency;
            }

            if (sumFrequencies.ContainsKey(sum))
            {
                ++sumFrequencies[sum];
            }
            else
            {
                sumFrequencies.Add(sum, 1);
            }
        }

        return result;
    }
}