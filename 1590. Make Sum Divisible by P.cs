public class Solution
{
    public int MinSubarray(int[] nums, int p)
    {
        var sum = 0;
        foreach (var num in nums)
        {
            sum += num;
            sum %= p;
        }
        var remainder = sum % p;

        if (remainder != 0)
        {
            var result = nums.Length;
            var remainders = new Dictionary<int, int>
            {
                { 0, -1 }
            };
            var prefixSum = 0;
            
            for (int i = 0; i < nums.Length; ++i)
            {
                prefixSum += nums[i];
                prefixSum %= p;
                var sumToRemove = (prefixSum - remainder + p) % p;

                if (remainders.TryGetValue(sumToRemove, out var ind))
                {
                    result = Math.Min(result, i - ind);
                }

                remainders[prefixSum] = i;
            }

            return result != nums.Length ? result : -1; 
        }
        else
        {
            return 0;
        }
    }
}