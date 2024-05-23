public class Solution
{
    public int BeautifulSubsets(int[] nums, int k)
    {
        Array.Sort(nums);
        var frequencies = nums.Distinct().ToDictionary(x => x, x => 0);

        return CountBeautifulSubsets(0, nums, k, frequencies) - 1;
    }

    private int CountBeautifulSubsets(int index, int[] nums, int k, IDictionary<int, int> frequencies)
    {
        if (index < nums.Length)
        {
            int currentCount = CountBeautifulSubsets(index + 1, nums, k, frequencies);

            if (!frequencies.TryGetValue(nums[index] - k, out var value) || value == 0)
            {
                ++frequencies[nums[index]];
                currentCount += CountBeautifulSubsets(index + 1, nums, k, frequencies);
                --frequencies[nums[index]];
            }

            return currentCount;
        }
        else
        {
            return 1;
        }
    }
}