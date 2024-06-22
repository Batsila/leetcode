public class Solution
{
    public int NumberOfSubarrays(int[] nums, int k)
    {
        var result = 0;
        var currentSum = 0;
        var prefixSum = new Dictionary<int, int>
        {
            { 0, 1 }
        };

        foreach (var num in nums)
        {
            currentSum += num % 2;

            if (prefixSum.TryGetValue(currentSum - k, out var value))
            {
                result += value;
            }

            if (prefixSum.ContainsKey(currentSum))
            {
                ++prefixSum[currentSum];
            }
            else
            {
                prefixSum.Add(currentSum, 1);
            }
        }

        return result;
    }
}