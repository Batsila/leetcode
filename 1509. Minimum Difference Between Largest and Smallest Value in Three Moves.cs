public class Solution
{
    public int MinDifference(int[] nums)
    {
        if (nums.Length > 4)
        {
            Array.Sort(nums);
            var result = int.MaxValue;

            for (int i = 0; i < 4; ++i)
            {
                result = Math.Min(result, nums[^(4 - i)] - nums[i]);
            }

            return result;
        }
        else
        {
            return 0;
        }
    }
}