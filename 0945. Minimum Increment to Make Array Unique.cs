public class Solution
{
    public int MinIncrementForUnique(int[] nums)
    {
        Array.Sort(nums);
        var result = 0;

        for (int i = 1; i < nums.Length; ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                result += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return result;
    }
}