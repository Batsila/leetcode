public class Solution
{
    public int SmallestDistancePair(int[] nums, int k)
    {
        var distanceFrequencies = new int[nums.Max() + 1];

        for (int i = 0; i < nums.Length; ++i)
        {
            for (int j = i + 1; j < nums.Length; ++j)
            {
                var distance = Math.Abs(nums[i] - nums[j]);
                ++distanceFrequencies[distance];
            }
        }

        for (int i = 0; i < distanceFrequencies.Length; ++i)
        {
            k -= distanceFrequencies[i];

            if (k <= 0)
            {
                return i;
            }
        }

        return -1;
    }
}